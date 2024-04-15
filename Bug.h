//
// Created by Harjappan Singh on 02/04/24.
//

#include <iostream>
#include <utility>
#include <list>
using namespace std;

enum direction {
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H


class Bug {
protected:
    int id;
    pair<int,int> position;
    direction direction;
    int size;
    bool alive;
    list<pair<int,int>> path;

public:
    Bug();
    Bug(int id, pair<int,int> position, enum direction, int size, bool alive, list<pair<int,int>> path);
    pair<int,int> getPosition() const;
    enum direction getDirection() const;
    int getSize() const;
    virtual void move() = 0;
    bool isWayBlocked() const;

};


#endif //BUG_LIFE_PROJECT_BUG_H
