#include <iostream>
#include <list>
using namespace std;

void printMenu();
int readInt(const string& message);

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}


void printMenu() {
    cout << "Welcome to the Bug Game!" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "1. Display all the bugs on the board" << endl;
    cout << "2. Find a bug by id" << endl;
    cout << "3. Tap the bug board" << endl;
    cout << "4. Display the life history of all the bugs" << endl;
    cout << "5. Exit" << endl;
    cout << "6. Display all cells" << endl;
}

int readInt(const string& message) {
    int input;
    while (true) {
        cout << message;
        string line;
        if (!getline(cin, line)) {
            cerr << "Error: failed to read input\n";
            exit(1);
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