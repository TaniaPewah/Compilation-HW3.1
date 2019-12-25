#ifndef PARSER
#define PARSER
    #include "output.hpp"
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

    #define NA -1
    using namespace std;

    enum Types {
        NONE,
        VOID_TYPE,
        BOOL_TYPE,
        BYTE_TYPE,
        INT_TYPE,
        STRING_TYPE,
    };

    class Node {
        public:
            int lineno;
            Node(int lineno): lineno(lineno) {};
    };

    class TypeNode : public Node {
        public:
            Types type;
            TypeNode(Types type, int lineno): Node(lineno), type(type) {};
    };

    class IdNode : public Node {
        public:
            string name;
            IdNode(char* name, int lineno): Node(lineno), name(name) {};
    };

    class NumNode : public Node {
        public:
            int num;
            NumNode(char* num, int lineno): Node(lineno), num(atoi(num)) {};
            string getAsString() {
                char buffer[256];
                sprintf(buffer, "%d", num);
                return buffer;
            }
    };

    class StringNode : public Node {
        public:
            string str;
            StringNode(char* str, int lineno): Node(lineno), str(str) {};
    };

    class OpNode : public Node {
        public:
            OpNode(int lineno): Node(lineno) {};
    };

    class CallNode : public Node {
        public:
            Types type;
            CallNode(Types type, int lineno): Node(lineno), type(type) {};
    };

    class ExpNode: public Node {
        public:
            Types type;
            ExpNode(Types type, int lineno): Node(lineno), type(type) {};
    };

    class ExpListNode :  public Node {
        public:
            vector<Types> types;
            ExpListNode(Types type, int lineno): Node(lineno) {
                types.insert(types.begin(),type);
            }

            void add(Types type) {
                types.insert(types.begin(),type);
            }

            bool compareType(vector<Types> args){
                if (args.size() != types.size()) {
                    return false;
                }

                for (vector<Types>::iterator it1 = args.begin(), it2 = types.begin(); it1 != args.end(); ++it1, ++it2){
                    if (*it1 != *it2 && !(*it1 == INT_TYPE && *it2 == BYTE_TYPE)) {
                        return false;
                    }
                }
                return true;
            }
    };

    class StatementNode : public Node {
        public:
            StatementNode(): Node(NA) {};
    };

    class PreCondNode : public Node {
        public:
            PreCondNode(): Node(NA) {};
    };

    class FormalDeclNode : public Node {
        public:
            Types type;
            string name;
            FormalDeclNode(Types type, string name, int lineno): Node(lineno), type(type), name(name) {};
    };

    class FormalsListNode : public Node {
        public:
            vector<Types> types;
            vector<string> names;
            FormalsListNode(Types type, string name, int lineno): Node(lineno) {
                types.insert(types.begin(), type);
                names.insert(names.begin(), name);
            }

            bool add(Types type, string name, int lineno) {
                for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
                    // check for already defined
                    if (name == *it) {
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
            FormalsNode(): Node(NA), isEmpty(true) {};
            FormalsNode(vector<Types> types, vector<string> names, int lineno): Node(lineno), types(types), names(names), isEmpty(false) {};
    };

    string typeToString(Types type);
    vector<string> typeToStringVector(vector<Types>& types);
    void checkOpTypes(ExpNode* exp1, ExpNode* exp2, int lineno);

    #define YYSTYPE Node*

    /* Symbol Table */

    class TableEntry {
        public:
            string name;
            Types type;
            int offset;
            bool isFunction;
            vector<Types> argTypes;

            TableEntry(string name, Types type, int offset): name(name), type(type), offset(offset), isFunction(false) {};
            TableEntry(string name, Types returnType, int offset, vector<Types> argTypes): name(name), type(returnType), offset(offset), isFunction(true), argTypes(argTypes) {};
    };

    class NotFound : public exception {};

    class Scope {
        private:

            vector<TableEntry> entries;
            int nextArgOffset;
            string functionName;
            int preConds;

        public:

            bool isFunctionScope;
            bool isInnerScope;
            bool isWhileScope;
            int nextOffset;

            Scope(): nextArgOffset(-1), functionName(), preConds(0), isFunctionScope(false), isInnerScope(false), isWhileScope(false), nextOffset(0) {}

            Scope(string functionName): nextArgOffset(-1), functionName(functionName), preConds(0), isFunctionScope(true), isInnerScope(false), isWhileScope(false), nextOffset(0) {}

            Scope(bool isInnerScope, bool isWhileScope = false, int nextOffset = 0): nextArgOffset(-1), functionName(), preConds(0), isFunctionScope(false), isInnerScope(isInnerScope), isWhileScope(isWhileScope), nextOffset(nextOffset) {}

            // End Scope
            void endScope() {
                output::endScope();

                if (this->isFunctionScope) {
                    output::printPreconditions(this->functionName, this->preConds);
                }

                for (int i = 0; i < entries.size(); i++) {
                    if (entries[i].isFunction) {
                        string retType = typeToString(entries[i].type);
                        vector<string> argTypes = typeToStringVector(entries[i].argTypes);
                        string functionType = output::makeFunctionType(retType, argTypes);
                        output::printID(entries[i].name, entries[i].offset, functionType);
                    } else {
                        output::printID(entries[i].name, entries[i].offset, typeToString(entries[i].type));
                    }
                }
            }

            const TableEntry& getIdentifierEntry(string name) {
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

            void addVar(string name, Types type) {
                entries.push_back(TableEntry(name, type, nextOffset++));
            }

            void addArg(string name, Types type) {
                entries.push_back(TableEntry(name, type, nextArgOffset--));
            }

            void addPreCond() {
                this->preConds++;
            }

            const TableEntry& getLastEntry() {
                return entries.back();
            }
    };

    class SymbolTable {
        public:
            vector<Scope> stack;
            bool hasMain;

            SymbolTable(): hasMain(false) {
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

            bool addFunction(IdNode* id, Types returnType, vector<Types> argTypes, vector<string> argNames) {
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

                    stack[0].addArg(argNames[i], argTypes[i]);
                }

                return true;
            }

            bool addVar(IdNode* id, Types type){
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
                    } catch (NotFound& e) {}
                }

                return false;
            }

            bool isDefinedVar(string name){
                for (int i = 0; i < stack.size(); i++) {
                    try {
                        TableEntry entry = stack[i].getIdentifierEntry(name);
                        return !entry.isFunction;
                    } catch (NotFound& e) {}
                }

                return false;
            }

            bool isAlreadyDefined(string name){
                for (int i = 0; i < stack.size(); i++) {
                    try {
                        TableEntry entry = stack[i].getIdentifierEntry(name);
                        return true;
                    } catch (NotFound& e) {}
                }

                return false;
            }

            Types getType(string name){
                for (int i = 0; i < stack.size(); i++) {
                    try {
                        TableEntry entry = stack[i].getIdentifierEntry(name);
                        return entry.type;
                    } catch (NotFound& e) {}
                }

                return NONE;
            }

            vector<Types> getFunctionArgs(string name){
                for (int i = 0; i < stack.size(); i++) {
                    try {
                        TableEntry entry = stack[i].getIdentifierEntry(name);
                        return entry.argTypes;
                    } catch (NotFound& e) {}
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

            void addPreCondToScope() {
                stack[0].addPreCond();
            }
    };

#endif
