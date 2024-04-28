//
// Created by Harjappan Singh on 22/04/24.
//

#include "Board.h"
#include "Hopper.h"
#include "Crawler.h"
#include "Bug.h"
#include "Bishop.h"
#include "Direction.h"
#include "InputValidator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <thread>
using namespace std;

Board::Board() {
//    for (int i = 0; i <s BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            cells[i][j] = make_pair(i,j);
//        }
//    }
}

void Board::initialiseBoard(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File not found" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream lineStream(line);
        vector<string> lineData;
        string bugType, bugIdStr, bugXStr, bugYStr, directionStr, sizeStr, hopLengthStr, bishopLengthStr;
        getline(lineStream, bugType, ';');
        getline(lineStream, bugIdStr, ';');
        getline(lineStream, bugXStr, ';');
        getline(lineStream, bugYStr, ';');
        getline(lineStream, directionStr, ';');
        getline(lineStream, sizeStr, ';');
        if (bugType == "H") {
            getline(lineStream, hopLengthStr, ';');
        }
        if (bugType == "B") {
            getline(lineStream, bishopLengthStr, ';');
        }

        int numOfInvalid = 1;
        if (!isValidBugData(bugType, bugIdStr, bugXStr, bugYStr, directionStr, sizeStr, hopLengthStr, bishopLengthStr)){
            cout << "Error: Invalid bug data -" << numOfInvalid << endl;
            numOfInvalid++;
            continue;
        }

        int bugId = stoi(bugIdStr);
        int bugX = stoi(bugXStr);
        int bugY = stoi(bugYStr);
        int direction = stoi(directionStr);
        int size = stoi(sizeStr);
        int hopLength = 0;
        int bishopLength = 0;
        if(bugType == "B"){
            bishopLength = stoi(bishopLengthStr);
            createBishopBug(bugId, bugX, bugY, direction, size, bishopLength);
        }
        else if (bugType == "H") {
            hopLength = stoi(hopLengthStr);
            createHopperBug(bugId, bugX, bugY, direction, size, hopLength);
        } else {
            createCrawlerBug(bugId, bugX, bugY, direction, size);
        }
    }
}

bool Board::isValidBugData(const string &bugType, const string &bugIdStr, const string &bugXStr,
                           const string &bugYStr, const string &directionStr, const string &sizeStr,
                           const string &hopLengthStr, const string &bishopLengthStr) const {
    int bugId = stoi(bugIdStr);
    int bugX = stoi(bugXStr);
    int bugY = stoi(bugYStr);
    int direction = stoi(directionStr);
    int size = stoi(sizeStr);

    if (bugType != "C" && bugType != "H" && bugType != "B") {
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
    if (direction < 1 || direction > 8) {
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
    if (bugType == "B") {
        int bishopLength = stoi(bishopLengthStr);
        if (bishopLength <= 0 || bishopLength > 6) {
            return false;
        }
    }
    return true;
}

void Board::createHopperBug(int bugId, int bugX, int bugY, int direction, int size, int hopLength) {
    Hopper* hopper = new Hopper(bugId, make_pair(bugX, bugY), static_cast<Direction>(direction), size, true, hopLength);
    hopper->addPath(make_pair(bugX, bugY));
    int position = (bugY * BOARD_SIZE) + bugX;
    cells[position].push_back(hopper);
    bugs.push_back(hopper);
}

void Board::createCrawlerBug(int bugId, int bugX, int bugY, int direction, int size) {
    Crawler* crawler = new Crawler(bugId, make_pair(bugX, bugY), static_cast<Direction>(direction), size, true);
    crawler->addPath(make_pair(bugX, bugY));
    int position = (bugY * BOARD_SIZE) + bugX;
    cells[position].push_back(crawler);
    bugs.push_back(crawler);
}

void Board::createBishopBug(int bugId, int bugX, int bugY, int direction, int size, int bishopLength) {
    Bishop *bishop = new Bishop(bugId, make_pair(bugX, bugY), static_cast<Direction>(direction), size, true,
                                bishopLength);
    bishop->addPath(make_pair(bugX, bugY));
    int position = (bugY * BOARD_SIZE) + bugX;
    cells[position].push_back(bishop);
    bugs.push_back(bishop);
}

void Board::displayAllBugs() const {
    for (int i = 0; i < 100; i++) {
        for (vector<Bug *>::const_iterator it = cells[i].cbegin(); it != cells[i].cend(); ++it) {
            (*it)->displayBug();
        }
    }
}

bool Board::isBoardEmpty() const {
    return cells->empty();
}

void Board::findBugById() const {
    int bugId = InputValidator::readInt("Enter bug id: ");
    for (int i = 0; i < 100; i++) {
        for (vector<Bug *>::const_iterator it = cells[i].cbegin(); it != cells[i].cend(); ++it) {
            if ((*it)->getId() == bugId) {
                (*it)->displayBug();
                return;
            }
        }
    }
    cout << "Bug " << bugId << " not found" << endl;
}

void Board::tapBoard() {
    if(countAliveBugs() == 1) {
        Bug *lastBug = findLastAliveBug();
        std::cout << "Last bug standing is bug " << lastBug->getId() << " at (" << lastBug->getPosition().first << "," << lastBug->getPosition().second << ")" << std::endl;
        return;
    }
    for (Bug *bug: bugs) {
        if (bug->isAlive()) {
            int oldPosition = bug->getPosition().second * BOARD_SIZE + bug->getPosition().first;
            bug->move();
            for (vector<Bug *>::iterator iter = cells[oldPosition].begin(); iter != cells[oldPosition].end(); ++iter) {
                if (*iter == bug) {
                    cells[oldPosition].erase(iter);
                    break;
                }
            }
            cells[bug->getPosition().second * BOARD_SIZE + bug->getPosition().first].push_back(bug);
        }
    }

    for (vector<Bug *> cell: cells) {
        if (cell.size() > 1) {
            Bug *biggestBug = nullptr;
            for (Bug *bug: cell) {
                if (bug->isAlive()) {
                    if (biggestBug == nullptr || bug->getSize() > biggestBug->getSize()) {
                        biggestBug = bug;
                    }
                }
            }
            if (biggestBug != nullptr) {
                for (Bug *bug: cell) {
                    if (bug->isAlive() && bug != biggestBug) {
                        bug->setAlive(false);
                        bug->setEatenBy(biggestBug->getId());
                        cout << bug->getId() << " eaten by " << biggestBug->getId() << endl;
                        biggestBug->setSize(biggestBug->getSize() + bug->getSize());
                    }
                }
            }
        }
    }
}

void Board::displayLifeHistoryOfAllBugs(ostream &out) const {
    for (int i = 0; i < 100; i++) {
        for (Bug *bug: cells[i]) {
            out << bug->getId() << " ";
            if (dynamic_cast<Crawler *>(bug)) {
                out << "Crawler";
            } else if (dynamic_cast<Hopper *>(bug)) {
                out << "Hopper";
            }else if (dynamic_cast<Bishop *>(bug)) {
                out << "Bishop";
            }
            out << " Path: ";
            for (auto const &pos: bug->getPath()) {
                out << "(" << pos.first << "," << pos.second << ")";
                if (&pos != &bug->getPath().back()) {
                    out << ",";
                }
            }
            if (!bug->isAlive()) {
                out << " Eaten by " << bug->getPredator();
            }
            out << endl;
        }
    }
}

void Board::writeLifeHistoryOfAllBugsToFile() const {
    filesystem::path dir_path = filesystem::current_path().parent_path();

    string file_name = "bugs_life_history_" + InputValidator::getCurrentDateTime() + ".out";
    replace(file_name.begin(), file_name.end(), ':', '_');
    filesystem::path file_path = dir_path / file_name;

    ofstream file(file_path);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file for writing.");
    }

    displayLifeHistoryOfAllBugs(file);
    if (!file.good()) {
        throw runtime_error("Error writing to file.");
    }
    cout << "Life history of all bugs written to file: " << file_path << endl;
    file.close();
}

void Board::displayAllCells() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << "(" << i << "," << j << "): ";
            bool empty = true;
            for (const auto &cell: cells) {
                for (Bug *bug: cell) {
                    if (bug->getPosition() == make_pair(i, j) && bug->isAlive()) {
                        empty = false;
                        if (dynamic_cast<Crawler *>(bug)) {
                            cout << "Crawler " << bug->getId() << " ";
                        } else if (dynamic_cast<Hopper *>(bug)) {
                            cout << "Hopper " << bug->getId() << " ";
                        }else if (dynamic_cast<Bishop *>(bug)) {
                            cout << "Bishop " << bug->getId() << " ";
                        }
                    }
                }
            }
            if (empty) {
                cout << "empty" << endl;
            } else {
                cout << endl;
            }
        }
    }
}

void Board::simulate() {
    int numBugs = countAliveBugs();
    int round = 1;
    while (numBugs > 1) {
        cout << "Round " << round << ":" << endl;
        tapBoard();
        displayAllBugs();
        numBugs = countAliveBugs();
        round++;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Bug " << findLastAliveBug()->getId() << " is the survivor." << endl;
    writeLifeHistoryOfAllBugsToFile();
}

int Board::countAliveBugs() const {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        for (Bug *bug: cells[i]) {
            if (bug->isAlive()) {
                count++;
            }
        }
    }
    return count;
}

Bug* Board::findLastAliveBug() const {
    for (int i = 0; i < 100; i++) {
        for (Bug *bug: cells[i]) {
            if (bug->isAlive()) {
                return bug;
            }
        }
    }
    return nullptr;
}

Board::~Board() {
    for (int i = 0; i <= 99; i++) {
        for (vector<Bug *>::iterator it = cells[i].begin(); it != cells[i].end(); ++it) {
            delete *it;
            cout << "deleting bug" << endl;
        }
    }
}