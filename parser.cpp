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


Types ExpNode::binopResType(Types a, Types b) {
    if ((a != INT_TYPE && a != BYTE_TYPE) || (b != INT_TYPE && b != BYTE_TYPE)) {
        string exceptionMessage("binopResType non-numerical types");
        throw (semErr(exceptionMessage));
    }
    return (a == INT_TYPE || b == INT_TYPE) ? INT_TYPE : BYTE_TYPE;
}

bool ExpNode::isNumTypes(Types type1, Types type2) {
    return ((type1 == INT_TYPE || type1 == BYTE_TYPE) && (type2 == INT_TYPE || type2 == BYTE_TYPE));
}
