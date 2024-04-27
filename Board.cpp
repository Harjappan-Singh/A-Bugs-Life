//
// Created by Harjappan Singh on 22/04/24.
//

#include "Board.h"
#include "Hopper.h"
#include "Crawler.h"
#include "Bug.h"
#include "Direction.h"
#include "InputValidator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

Board::Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cells[i][j] = make_pair(i,j);
        }
    }
}

void Board::initialiseBoard(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {cout << "Error: File not found" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream lineStream(line);
        vector<string> lineData;
        string bugType, bugIdStr, bugXStr, bugYStr, directionStr, sizeStr, hopLengthStr;
        getline(lineStream, bugType, ';');
        getline(lineStream, bugIdStr, ';');
        getline(lineStream, bugXStr, ';');
        getline(lineStream, bugYStr, ';');
        getline(lineStream, directionStr, ';');
        getline(lineStream, sizeStr, ';');
        getline(lineStream, hopLengthStr, ';');
        if (bugType == "H") {
            getline(lineStream, hopLengthStr, ';');
        }

        if (!isValidBugData(bugType, bugIdStr, bugXStr, bugYStr, directionStr, sizeStr, hopLengthStr)) {
            cout << "Error: Invalid bug data" << endl;
            continue;
        }

        int bugId = stoi(bugIdStr);
        int bugX = stoi(bugXStr);
        int bugY = stoi(bugYStr);
        int direction = stoi(directionStr);
        int size = stoi(sizeStr);
        int hopLength = 0;

        if (bugType == "H") {
            hopLength = stoi(hopLengthStr);
            createHopperBug(bugId, bugX, bugY, direction, size, hopLength);
        } else {
            createCrawlerBug(bugId, bugX, bugY, direction, size);
        }
    }
}

bool Board::isValidBugData(const string& bugType, const string& bugIdStr, const string& bugXStr, const string& bugYStr, const string& directionStr, const string& sizeStr, const string& hopLengthStr) const {
    int bugId = stoi(bugIdStr);
    int bugX = stoi(bugXStr);
    int bugY = stoi(bugYStr);
    int direction = stoi(directionStr);
    int size = stoi(sizeStr);

    if (bugType != "C" && bugType != "H") {
        return false;
    }
    if (bugId <= 0) {
        return false;
    }
    if (bugX < 0 || bugX >= BOARD_SIZE) {
        return false;
    }
    if (bugY < 0 || bugY >= BOARD_SIZE) {
        return false;
    }
    if (direction < 1 || direction > 4) {
        return false;
    }
    if (size <= 0) {
        return false;
    }
    if (bugType == "H") {
        int hopLength = stoi(hopLengthStr);
        if (hopLength <= 0) {
            return false;
        }
    }
    return true;
}

void Board::createHopperBug(int bugId, int bugX, int bugY, int direction, int size, int hopLength) {
    Hopper* hopper = new Hopper(bugId, make_pair(bugX, bugY), static_cast<Direction>(direction), size, true, hopLength);
    bug_vector.push_back(hopper);
}

void Board::createCrawlerBug(int bugId, int bugX, int bugY, int direction, int size) {
    Crawler* crawler = new Crawler(bugId, make_pair(bugX, bugY), static_cast<Direction>(direction), size, true);
    bug_vector.push_back(crawler);
}

void Board::displayAllBugs() const {
    for (const auto& bug : bug_vector) {
        cout << bug->getId() << " ";
        if (dynamic_cast<Crawler*>(bug)) {
            cout << "Crawler ";
        } else {
            cout << "Hopper ";
        }
        cout << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
        cout << bug->getSize() << " ";

        switch (bug->getDirection()) {
            case Direction::North:
                cout << "North ";
                break;
            case Direction::East:
                cout << "East ";
                break;
            case Direction::South:
                cout << "South ";
                break;
            case Direction::West:
                cout << "West ";
                break;
        }

        if (dynamic_cast<Hopper*>(bug)) {
            cout << dynamic_cast<Hopper*>(bug)->getHopLength() << " ";
        } else {
            cout << "- ";
        }

        if (bug->isAlive()) {
            cout << "Alive";
        } else {
            cout << "Dead";
        }

        cout << endl;
    }
}

bool Board::isBugVectorEmpty() const{
    return bug_vector.empty();
}

void Board::findBugById() const {
    int bugId = InputValidator::readInt("Enter bug id: ");
    for (Bug* bug : bug_vector) {
        if (bug->getId() == bugId) {
            bug->displayBug();
            return;
        }
    }
    cout << "Bug " << bugId << " not found" << endl;
}

void Board::tapBoard() {
    for (Bug* bug : bug_vector) {
        bug->move();
    }
}

Board::~Board() {
    for (auto & i : bug_vector) {
        delete i;
    }
}