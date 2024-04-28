//
// Created by Harjappan Singh on 02/04/24.
//



#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H
#include <iostream>
#include <utility>
#include <list>
#include "Direction.h"
using namespace std;

class Bug {
protected:
    int id;
    pair<int,int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int,int>> path;
    int predator;

public:
    Bug();

    Bug(int id, pair<int,int> position,Direction direction, int size, bool alive);

    int getId() const;

    void setId(int id);

    const pair<int, int>& getPosition() const;

    void setPosition(const pair<int, int>& position);

    Direction getDirection() const;

    void setDirection(Direction direction);

    int getSize() const;

    void setSize(int size);

    bool isAlive() const;

    void setAlive(bool alive);

    const list<pair<int, int>>& getPath() const;

    void setPath(const list<pair<int, int>>& path);

    void addPath(const pair<int, int>& position);

    int getPredator() const;

    void setEatenBy(const int& predator);

    virtual void move() = 0;

    bool isWayBlocked() const;

    virtual void displayBug()=0;

    virtual ~Bug();

};

#endif //BUG_LIFE_PROJECT_BUG_H
