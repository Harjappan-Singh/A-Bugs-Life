//
// Created by Harjappan Singh on 22/04/24.
//

#include "Hopper.h"
Hopper::Hopper() {
    hopLength = 0;
}

Hopper::Hopper(int id, pair<int, int> position, enum direction direction, int size, bool alive, int hopLength) : Bug(id, position, direction, size, alive) {
    this->hopLength = hopLength;
}

int Hopper::getHopLength() const {
    return hopLength;
}

void Hopper::setHopLength(int h) {
    Hopper::hopLength = h;
}


void Hopper::move() {
    while (isWayBlocked()) {
        int newDirection = rand() % 4 + 1;
        setDirection((enum direction) newDirection);
    }
    pair<int, int> currentPosition = getPosition();
    enum direction currentDirection = getDirection();
    list<pair<int, int>> currentPath = getPath();

    int maxHopDistance = 0;
    switch (currentDirection) {
        case North:
            maxHopDistance = currentPosition.second;
            break;
        case East:
            maxHopDistance = 9 - currentPosition.first;
            break;
        case South:
            maxHopDistance = 9 - currentPosition.second;
            break;
        case West:
            maxHopDistance = currentPosition.first;
            break;
    }

    if (maxHopDistance >= hopLength) {
        switch (currentDirection) {
            case North:
                currentPosition.second -= hopLength;
                break;
            case East:
                currentPosition.first += hopLength;
                break;
            case South:
                currentPosition.second += hopLength;
                break;
            case West:
                currentPosition.first -= hopLength;
                break;
        }
        setPosition(currentPosition);
        currentPath.push_back(currentPosition);
        setPath(currentPath);
    }
    else {
        switch (currentDirection) {
            case North:
                currentPosition.second = 0;
                break;
            case East:
                currentPosition.first = 9;
                break;
            case South:
                currentPosition.second = 9;
                break;
            case West:
                currentPosition.first = 0;
                break;
        }
        setPosition(currentPosition);
        currentPath.push_back(currentPosition);
        setPath(currentPath);
    }
}

Hopper::~Hopper() {

}