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
    bool result;
    if(this->direction == Direction::North){
        result = this->position.second == 0;
    } else if(this->direction == Direction::East){
        result = this->position.first == 9;
    } else if(this->direction == Direction::South){
        result = this->position.second == 9;
    } else if(this->direction == Direction::West){
        result = this->position.first == 0;
    } else{
        result = false;
    }
    return result;
}

Bug::~Bug() {
    cout << "Bug destructor has been called" << endl;
}