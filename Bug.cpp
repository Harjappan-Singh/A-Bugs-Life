//
// Created by Harjappan Singh on 02/04/24.
//

#include "Bug.h"
#include "Direction.h"

Bug::Bug(){
    this->id = 0;
    this->position = make_pair(0,0);
    this->direction = Direction::North;
    this->size = 0;
    this->alive = false;
}

Bug::Bug(int id, pair<int, int> position, Direction direction, int size, bool alive) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
}

int Bug::getId() const {
    return id;
}

void Bug::setId(int i) {
    Bug::id = i;
}

const pair<int, int> &Bug::getPosition() const {
    return position;
}

void Bug::setPosition(const pair<int, int> &ps) {
    Bug::position = ps;
}

Direction Bug::getDirection() const {
    return direction;
}

void Bug::setDirection(Direction d) {
    Bug::direction = d;
}

int Bug::getSize() const {
    return size;
}

void Bug::setSize(int s) {
    Bug::size = s;
}

bool Bug::isAlive() const {
    return alive;
}

void Bug::setAlive(bool a) {
    Bug::alive = a;
}

const list<pair<int, int>> & Bug::getPath() const {
    return path;
}

void Bug::setPath(const list<pair<int, int>> &p) {
    Bug::path = p;
}

bool Bug::isWayBlocked() const{
    const int BOARD_SIZE = 10;
    bool wayBlocked = false;
    switch (direction) {
        case Direction::North:
            wayBlocked = (position.second == 0);
            break;
        case Direction::East:
            wayBlocked = (position.first == (BOARD_SIZE - 1));
            break;
        case Direction::South:
            wayBlocked = (position.second == (BOARD_SIZE - 1));
            break;
        case Direction::West:
            wayBlocked = (position.first == 0);
            break;
        default:
            break;
    }
    return wayBlocked;
}

Bug::~Bug() {
    cout << "Bug destructor has been called" << endl;
}