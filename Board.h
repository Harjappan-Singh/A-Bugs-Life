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

    vector<Bug*> bug_vector;

    pair<int,int> cells[BOARD_SIZE][BOARD_SIZE];

public:
    Board();
    void initialiseBoard(const string& filename);
    bool isValidBugData(const string& bugType, const string& bugIdStr, const string& bugXStr, const string& bugYStr, const string& directionStr, const string& sizeStr, const string& hopLengthStr) const;
    void createHopperBug(int bugId, int bugX, int bugY, int direction, int size, int hopLength);
    void createCrawlerBug(int bugId, int bugX, int bugY, int direction, int size);
    void displayAllBugs() const;
    bool isBugVectorEmpty() const;
    void findBugById() const;
    ~Board();
};


#endif //BUG_LIFE_PROJECT_BOARD_H
