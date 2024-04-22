//
// Created by Harjappan Singh on 22/04/24.
//

#include "InputValidator.h"
#include <iostream>
#include <string>
#include <stdexcept>

namespace InputValidator {
    int readInt(const string& message) {
        int input;
        while (true) {
            cout << message;
            string line;
            if (!getline(cin, line)) {
                throw runtime_error("Error: failed to read input");
            }
            try {
                input = stoi(line);
                break;
            } catch (invalid_argument& e) {
                cout << "Invalid input, please enter an integer.\n";
            } catch (out_of_range& e) {
                cout << "Input out of range, please enter an integer.\n";
            }
        }
        return input;
    }

    string readString(const string& message) {
        cout << message;
        string line;
        if (!getline(cin, line)) {
            cerr << "Error: failed to read input\n";
            exit(1);
        }
        return line;
    }
}