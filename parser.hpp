#ifndef PARSER
#define PARSER

#include "hw3_output.hpp"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <memory>
#include <iostream>

#define NA -1
using namespace std;

enum Types {
    NONE,
    VOID_TYPE,
    BOOL_TYPE,
    BYTE_TYPE,
    INT_TYPE,
    ENUM_TYPE,
    STRING_TYPE,
};

enum Operation {
    ADD_OP,
    SUB_OP,
    MUL_OP,
    DIV_OP,
    OR_OP,
    AND_OP,
    NOT_OP
};

class semErr : public std::exception {
public:
    semErr(const string msg) : m_msg(msg) {}

    const char *what() const noexcept override {
        cout << "debug - what:" << m_msg << endl;
        return m_msg.c_str();
    }

    const string m_msg;
};

class Node {
public:
    int lineno;

    Node(int lineno) : lineno(lineno) {};
};

class TypeNode : public Node {
public:
    Types type;

    TypeNode(Types type, int lineno) : Node(lineno), type(type) {};
};

class IdNode : public Node {
public:
    string name;

    IdNode(char *name, int lineno) : Node(lineno), name(name) {};
};

class NumNode : public Node {
public:
    int num;

    NumNode(char *num, int lineno) : Node(lineno), num(atoi(num)) {};

    string getAsString() {
        char buffer[256];
        sprintf(buffer, "%d", num);
        return buffer;
    }
};

class StringNode : public Node {
public:
    string str;

    StringNode(char *str, int lineno) : Node(lineno), str(str) {};
};

class BinopNode : public Node {
public:
    Operation operation;
    BinopNode(int lineno, Operation op) : Node(lineno), operation(op) {};
};

class RelopNode : public Node {
public:
    RelopNode(int lineno) : Node(lineno) {};
};

class AssignNode : public Node {
public:
    AssignNode(int lineno) : Node(lineno) {};
};

class CallNode : public Node {
public:
    Types type;

    CallNode(Types type, int lineno) : Node(lineno), type(type) {};
};

class ExpNode : public Node {
    bool isNumTypes(Types type1, Types type2);
    Types binopResType(Types a, Types b);
public:
    Types type;

    ExpNode(Types type, int lineno) : Node(lineno), type(type) {};
    ExpNode(Types type1, Types type2, int lineno, BinopNode* node) : Node(lineno) {
        try {
            type = binopResType(type1, type2);
        } catch (exception &e) {
            output::errorMismatch(lineno);
        }
    };

    ExpNode(Types type1, Types type2, int lineno, RelopNode* node) : Node(lineno) {
        if (isNumTypes(type1, type2)) output::errorMismatch(lineno);
        type = BOOL_TYPE;
    };
};

class ExpListNode : public Node {
public:
    vector<Types> types;

    ExpListNode(Types type, int lineno) : Node(lineno) {
        types.insert(types.begin(), type);
    }

    void add(Types type) {
        types.insert(types.begin(), type);
    }

    bool compareType(vector<Types> args) {
        if (args.size() != types.size()) {
            return false;
        }

        for (auto it1 = args.begin(), it2 = types.begin(); it1 != args.end(); ++it1, ++it2) {
            if (*it1 != *it2 && !(*it1 == INT_TYPE && *it2 == BYTE_TYPE)) {
                return false;
            }
        }
        return true;
    }
};

class EnumeratorListNode : public Node {
public:
    vector<string> enums;

    EnumeratorListNode(string enumVal, int lineno) : Node(lineno) {
        enums.insert(enums.begin(), enumVal);
    }

    bool add(string enumVal, int lineno) {
        for (auto &it : enums) {
            // check if already defined
            if (enumVal == it) {
                output::errorDef(lineno, enumVal);
                return false;
            }
        }
        enums.insert(enums.begin(), enumVal);
        return true;
    }
};

class EnumDeclNode : public Node {
public:
    string name;

    EnumDeclNode(string enumName, int lineno) : Node(lineno), name(enumName) {}
};



class EnumeratorNode : public Node {
public:
    string name;

    EnumeratorNode(string enumVal, int lineno) : Node(lineno), name(enumVal) {}
};

class StatementNode : public Node {
public:
    StatementNode() : Node(NA) {};
};

class FormalDeclNode : public Node {
public:
    Types type;
    string name;

    FormalDeclNode(Types type, string name, int lineno) : Node(lineno), type(type), name(name) {};
};

class FormalsListNode : public Node {
public:
    vector<Types> types;
    vector<string> names;

    FormalsListNode(Types type, string name, int lineno) : Node(lineno) {
        types.insert(types.begin(), type);
        names.insert(names.begin(), name);
    }

    bool add(Types type, string name, int lineno) {
        for (auto &it : names) {
            // check if already defined
            if (name == it) {
                output::errorDef(lineno, name);
                return false;
            }
        }

        types.insert(types.begin(), type);
        names.insert(names.begin(), name);
        return true;
    }
};

class FormalsNode : public Node {
public:
    vector<Types> types;
    vector<string> names;
    bool isEmpty;

    FormalsNode() : Node(NA), isEmpty(true) {};

    FormalsNode(vector<Types> types, vector<string> names, int lineno) : Node(lineno), types(types), names(names),
                                                                         isEmpty(false) {};
};

string typeToString(Types type);

vector<string> typeToStringVector(vector<Types> &types);

#define YYSTYPE Node*

/* Symbol Table */

class TableEntry {
public:
    string name;
    Types type;
    int offset;
    bool isFunction;
    vector<Types> argTypes;
    vector<string> enumVals;

    TableEntry(string name, Types type, int offset) : name(name), type(type), offset(offset), isFunction(false) {};

    TableEntry(string name, Types returnType, int offset, vector<Types> argTypes) : name(name), type(returnType),
                                                                                    offset(offset), isFunction(true),
                                                                                    argTypes(argTypes) {};

    TableEntry(string name, int offset, vector<string> enumVals) : name(name), offset(offset), type(ENUM_TYPE),
                                                                   isFunction(true), enumVals(enumVals) {};
};

class NotFound : public exception {
};

class Scope {
private:

    vector<TableEntry> entries;
    int nextArgOffset;
    string functionName;

public:

    bool isFunctionScope;
    bool isInnerScope;
    bool isWhileScope;
    int nextOffset;

    Scope() : nextArgOffset(-1), functionName(), isFunctionScope(false), isInnerScope(false),
              isWhileScope(false), nextOffset(0) {}

    Scope(string functionName) : nextArgOffset(-1), functionName(functionName), isFunctionScope(true),
                                 isInnerScope(false), isWhileScope(false), nextOffset(0) {}

    Scope(bool isInnerScope, bool isWhileScope = false, int nextOffset = 0) : nextArgOffset(-1), functionName(),
                                                                              isFunctionScope(false),
                                                                              isInnerScope(isInnerScope),
                                                                              isWhileScope(isWhileScope),
                                                                              nextOffset(nextOffset) {}

    // End Scope
    void endScope() {
        output::endScope();

        for (auto & entry : entries) {
            if (entry.isFunction) {
                string retType = typeToString(entry.type);
                vector<string> argTypes = typeToStringVector(entry.argTypes);
                string functionType = output::makeFunctionType(retType, argTypes);
                output::printID(entry.name, entry.offset, functionType);
            } else {
                output::printID(entry.name, entry.offset, typeToString(entry.type));
            }
        }
    }

    const TableEntry &getIdentifierEntry(string name) {
        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].name == name) {
                return entries[i];
            }
        }

        throw NotFound();
    }

    bool isExists(string name) {
        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].name == name) {
                return true;
            }
        }

        return false;
    }

    void addFunction(string name, Types returnType, vector<Types> argTypes) {
        entries.push_back(TableEntry(name, returnType, 0, argTypes));
    }

    void addEnum(string name, vector<string> enumVals) {
        entries.push_back(TableEntry(name, 0, enumVals));
    }

    void addVar(string name, Types type) {
        entries.push_back(TableEntry(name, type, nextOffset++));
    }

    void addArg(string name, Types type) {
        entries.push_back(TableEntry(name, type, nextArgOffset--));
    }

    const TableEntry &getLastEntry() {
        return entries.back();
    }
};

class SymbolTable {
public:
    vector<Scope> stack;
    bool hasMain;

    SymbolTable() : hasMain(false) {
        Scope scope;

        // Adding print
        vector<Types> types;
        types.push_back(STRING_TYPE);
        scope.addFunction("print", VOID_TYPE, types);

        // Adding printi
        types = vector<Types>();
        types.push_back(INT_TYPE);
        scope.addFunction("printi", VOID_TYPE, types);

        // Insert the first scope to the stack
        stack.insert(stack.begin(), scope);
    }

    bool addFunction(IdNode *id, Types returnType, vector<Types> argTypes, vector<string> argNames) {
        if (id->name == "main" && returnType == VOID_TYPE && argTypes.size() == 0) {
            this->hasMain = true;
        }

        // Add function to current scope
        stack[0].addFunction(id->name, returnType, argTypes);

        // Open function's scope
        this->newFunctionScope(id->name);

        // Add all arguments names to the function's scope
        for (int i = 0; i < argTypes.size(); i++) { // argTypes and argNames are same size
            if (id->name == argNames[i] || stack[0].isExists(id->name)) {
                output::errorDef(id->lineno, id->name);
                return false;
            }
            if (argTypes[i] == ENUM_TYPE) {

            }
            stack[0].addArg(argNames[i], argTypes[i]);
        }

        return true;
    }

    bool addEnum(IdNode *id, vector<string> enumVals) {

        // Add Enum to current scope
        stack[0].addEnum(id->name, enumVals);

        // Add all enum vals to the current scope
        for (int i = 0; i < enumVals.size(); i++) { // argTypes and argNames are same size
            if (id->name == enumVals[i] || stack[0].isExists(id->name)) {
                output::errorDef(id->lineno, id->name);
                return false;
            }
        }

        return true;
    }

    bool addVar(IdNode *id, Types type) {
        if (stack[0].isExists(id->name)) {
            output::errorDef(id->lineno, id->name);
            return false;
        }

        stack[0].addVar(id->name, type);
        return true;
    }

    void endScope() {
        stack[0].endScope();
        stack.erase(stack.begin());
    }

    void newScope() {
        stack.insert(stack.begin(), Scope());
    }

    void newFunctionScope(string name) {
        stack.insert(stack.begin(), Scope(name));
    }

    void newInnerScope(bool isWhileScope = false) {
        int nextOffset = stack[0].nextOffset;
        stack.insert(stack.begin(), Scope(true /*isInnerScope*/, isWhileScope, nextOffset));
    }

    bool isInWhile() {
        for (int i = 0; i < stack.size(); i++) {
            if (stack[i].isWhileScope)
                return true;
        }

        return false;
    }

    bool isDefinedFunction(string name) {
        for (int i = 0; i < stack.size(); i++) {
            try {
                TableEntry entry = stack[i].getIdentifierEntry(name);
                return entry.isFunction;
            } catch (NotFound &e) {}
        }
        return false;
    }

    bool isDefinedVar(string name) {
        for (int i = 0; i < stack.size(); i++) {
            try {
                TableEntry entry = stack[i].getIdentifierEntry(name);
                return !entry.isFunction;
            } catch (NotFound &e) {}
        }
        return false;
    }

    bool isEnumDefined(string name) {
        for (int i = 0; i < stack.size(); i++) {
            try {
                TableEntry entry = stack[i].getIdentifierEntry(name);
                if (entry.type == ENUM_TYPE) return true;
            } catch (NotFound &e) {}
        }
        return false;
    }

    bool isAlreadyDefined(string name) {
        for (int i = 0; i < stack.size(); i++) {
            try {
                TableEntry entry = stack[i].getIdentifierEntry(name);
                return true;
            } catch (NotFound &e) {}
        }

        return false;
    }

    Types getType(string name) {
        for (int i = 0; i < stack.size(); i++) {
            try {
                TableEntry entry = stack[i].getIdentifierEntry(name);
                return entry.type;
            } catch (NotFound &e) {}
        }

        return NONE;
    }

    vector<Types> getFunctionArgs(string name) {
        for (int i = 0; i < stack.size(); i++) {
            try {
                TableEntry entry = stack[i].getIdentifierEntry(name);
                return entry.argTypes;
            } catch (NotFound &e) {}
        }

        return vector<Types>();
    }

    Types getCurrentFunctionRetType() {
        for (int i = 0; i < stack.size() - 1; i++) {
            if (stack[i].isFunctionScope)
                return stack[i + 1].getLastEntry().type;
        }

        return NONE;
    }
};

#endif
