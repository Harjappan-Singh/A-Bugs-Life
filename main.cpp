#include <iostream>
#include <list>
#include <string>
#include "Board.h"
using namespace std;

void printMenu();
int readInt(const string& message);
string readString(const string& message);

int main() {
    Board board;
//    string filename = readString("Enter the name of the file to read the bug data from: ");
    board.initialiseBoard("/Users/harjappansingh/Documents/College/Sophomore/Sem 2/C++/Bug_Life_Project/bugs.txt");
    while(true){
        printMenu();
        int choice = readInt("Please enter your choice: ");
        switch(choice){
            case 1:
                cout << "Displaying all the bugs on the board" << endl;
                if(board.isBugVectorEmpty()){
                    cout << "There are no bugs on the board" << endl;
                } else {
                    board.displayAllBugs();
                }
                break;
            case 2:
                cout << "Finding a bug by id" << endl;
                break;
            case 3:
                cout << "Tapping the bug board" << endl;
                break;
            case 4:
                cout << "Displaying the life history of all the bugs" << endl;
                break;
            case 5:
                cout << "Exiting" << endl;
                return 0;
            case 6:
                cout << "Displaying all cells" << endl;
                break;
            default:
                cout << "Invalid choice, please enter a number between 1 and 6" << endl;
                break;
        }
    }
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

string readString(const string& message) {
    cout << message;
    string line;
    if (!getline(cin, line)) {
        cerr << "Error: failed to read input\n";
        exit(1);
    }
    return line;
}