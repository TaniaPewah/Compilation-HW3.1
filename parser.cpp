#include "parser.hpp"

using namespace std;

string typeToString(Types type) {
    switch (type) {
        case BOOL_TYPE:
            return "BOOL";
        case BYTE_TYPE:
            return "BYTE";
        case INT_TYPE:
            return "INT";
        case STRING_TYPE:
            return "STRING";
        case VOID_TYPE:
            return "VOID";
        default:
            string exceptionMessage("typeToString non-exhaustive");
            throw (semErr(exceptionMessage));
    }
}

vector<string> typeToStringVector(vector<Types>& types) {
    vector<string> returnVector;
    for (int i = 0; i < types.size(); i++) {
        returnVector.push_back(typeToString(types[i]));
    }

    return returnVector;
}

void checkOpTypes(Node* expr1, Node* expr2, int lineno) {
    ExpNode* exp1 = (ExpNode*)expr1;
    ExpNode* exp2 = (ExpNode*)expr2;
    if (!(exp1->type == INT_TYPE && exp2->type == INT_TYPE
        || exp1->type == BYTE_TYPE && exp2->type == BYTE_TYPE
        || exp1->type == BYTE_TYPE && exp2->type == INT_TYPE
        || exp1->type == INT_TYPE && exp2->type == BYTE_TYPE)) {
            output::errorMismatch(lineno); 
            exit(0);
        }
}