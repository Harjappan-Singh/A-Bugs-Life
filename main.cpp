#include <iostream>
#include <list>
#include <string>
#include "Board.h"
#include "InputValidator.h"
using namespace std;

void printMenu();


int main() {
    Board board;
    string filename = InputValidator::readString("Enter the name of the file to read the bug data from: ");
    board.initialiseBoard("/Users/harjappansingh/Documents/College/Sophomore/Sem 2/C++/Bug_Life_Project/bugs.txt");
    while(true){
        printMenu();
        int choice = InputValidator::readInt("Please enter your choice: ");
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
                board.findBugById();
                break;
            case 3:
                cout << "Tapping the bug board" << endl;
                board.tapBoard();
                break;
            case 4:
                cout << "Displaying the life history of all the bugs" << endl;
                board.displayLifeHistoryOfAllBugs();
                break;
            case 5:
                cout << "Exiting" << endl;
                board.writeLifeHistoryOfAllBugsToFile();
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
