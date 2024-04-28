//
// Created by Harjappan Singh on 22/04/24.
//

#ifndef BUG_LIFE_PROJECT_BOARD_H
#define BUG_LIFE_PROJECT_BOARD_H

#include "Bug.h"
#include <vector>
#include "Direction.h"
class Board{
    static const int BOARD_SIZE = 10;

//    vector<Bug*> bug_vector;
//
//    pair<int,int> cells[BOARD_SIZE][BOARD_SIZE];

    vector <Bug*> cells[100];
    vector <Bug*> bugs;

public:
    Board();
    void initialiseBoard(const string& filename);
    bool isValidBugData(const string& bugType, const string& bugIdStr, const string& bugXStr, const string& bugYStr, const string& directionStr, const string& sizeStr, const string& hopLengthStr, const string& bishopLengthStr) const;
    void createHopperBug(int bugId, int bugX, int bugY, int direction, int size, int hopLength);
    void createCrawlerBug(int bugId, int bugX, int bugY, int direction, int size);
    void createBishopBug(int bugId, int bugX, int bugY, int direction, int size, int bisLength);
    void displayAllBugs() const;
    bool isBoardEmpty() const;
    void findBugById() const;
    void tapBoard();
    void displayLifeHistoryOfAllBugs(ostream& out = cout) const;
    void writeLifeHistoryOfAllBugsToFile() const;
    void displayAllCells() const;
    void fight(vector<Bug*> &vector_bug);
    int countAliveBugs() const;
    Bug* findLastAliveBug() const;
    void simulate();
    ~Board();
};


#endif //BUG_LIFE_PROJECT_BOARD_H
