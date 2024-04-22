//
// Created by Harjappan Singh on 02/04/24.
//



#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H
#include <iostream>
#include <utility>
#include <list>
using namespace std;

class Bug {
protected:
    int id;
    pair<int,int> position;
    enum direction {
        North = 1,
        East = 2,
        South = 3,
        West = 4
    } direction;
    int size;
    bool alive;
    list<pair<int,int>> path;

public:
    Bug();

    Bug(int id, pair<int,int> position, enum direction direction, int size, bool alive);

    int getId() const;

    void setId(int id);

    const pair<int, int>& getPosition() const;

    void setPosition(const pair<int, int>& position);

    enum direction getDirection() const;

    void setDirection(enum direction direction);

    void setDirection(int direction);

    int getSize() const;

    void setSize(int size);

    bool isAlive() const;

    void setAlive(bool alive);

    const list<pair<int, int>>& getPath() const;

    void setPath(const list<pair<int, int>>& path);

    virtual void move() = 0;

    bool isWayBlocked() const;

    virtual ~Bug();

};

#endif //BUG_LIFE_PROJECT_BUG_H
