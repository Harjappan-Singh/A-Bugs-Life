//
// Created by Harjappan Singh on 22/04/24.
//

#ifndef BUG_LIFE_PROJECT_INPUTVALIDATOR_H
#define BUG_LIFE_PROJECT_INPUTVALIDATOR_H
#include <string>

using namespace std;

namespace InputValidator {
    int readInt(const string& message);
    string readString(const string& message);
    string getCurrentDateTime();
}


#endif //BUG_LIFE_PROJECT_INPUTVALIDATOR_H
