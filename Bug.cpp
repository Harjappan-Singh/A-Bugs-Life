//
// Created by Harjappan Singh on 02/04/24.
//

#include "Bug.h"

Bug::Bug(){

}

Bug::Bug(int id, pair<int, int> position, enum direction, int size, bool alive, list<pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
}

pair<int, int> Bug::getPosition() const{
    return this->position;
}

enum direction Bug::getDirection() const {
    return this->direction;
}

int Bug::getSize() const {
    return this->size;
}

bool Bug::isWayBlocked() const{
    bool result;
    if(direction == North){
        result = this->position.second == 0;
    } else if(direction == East){
        result = this->position.first == 9;
    } else if(direction == South){
        result = this->position.second == 9;
    } else if(direction == West){
        result = this->position.first == 0;
    } else{
        result = false;
    }
    return result;
}