//
// Created by Harjappan Singh on 28/04/24.
//

#include "Bishop.h"
#include <iostream>

Bishop::Bishop() {
    bisLength = 0;
}

Bishop::Bishop(int id, pair<int, int> position, Direction direction, int size, bool alive, int bisLength) : Bug(id, position, direction, size, alive) {
    this->bisLength = bisLength;
}

int Bishop::getBisLength() const {
    return bisLength;
}

void Bishop::setBisLength(int b) {
    Bishop::bisLength = b;
}

// A Bishop bug moves according to these rules:
// - It moves by "bisLength" units in its current direction.
// - If it reaches the edge of the board and can't move over the edge in its current direction,
//   it sets a new direction at random (repeating until the bug can move forward) and then moves.
// - If the bug can't move the full 'bisLength', then it still moves but 'hits' the edge and falls
//   on the square where it hit the edge/wall.
// - The new position is recorded in the bishop's path history. The bishop can only move diagonally.
void Bishop::move(){
    while (isWayBlocked()) {
        int newDirection = rand() % 4 + 5;
        setDirection((Direction) newDirection);
    }

    pair<int, int> currentPosition = getPosition();
    Direction currentDirection = getDirection();
    list<pair<int, int>> currentPath = getPath();

    int maxHopDistance = 0;
    switch (currentDirection) {
        case NorthEast:
            maxHopDistance = min(currentPosition.second, 9 - currentPosition.first);
            break;
        case SouthEast:
            maxHopDistance = min(9 - currentPosition.second, 9 - currentPosition.first);
            break;
        case SouthWest:
            maxHopDistance = min(9 - currentPosition.second, currentPosition.first);
            break;
        case NorthWest:
            maxHopDistance = min(currentPosition.second, currentPosition.first);
            break;
    }

    if (maxHopDistance >= bisLength) {
        switch (currentDirection) {
            case NorthEast:
                currentPosition.first += bisLength;
                currentPosition.second -= bisLength;
                break;
            case SouthEast:
                currentPosition.first += bisLength;
                currentPosition.second += bisLength;
                break;
            case SouthWest:
                currentPosition.first -= bisLength;
                currentPosition.second += bisLength;
                break;
            case NorthWest:
                currentPosition.first -= bisLength;
                currentPosition.second -= bisLength;
                break;
        }
    } else {
        switch (currentDirection) {
            case NorthEast:
                currentPosition.first += maxHopDistance;
                currentPosition.second -= maxHopDistance;
                break;
            case SouthEast:
                currentPosition.first += maxHopDistance;
                currentPosition.second += maxHopDistance;
                break;
            case SouthWest:
                currentPosition.first -= maxHopDistance;
                currentPosition.second += maxHopDistance;
                break;
            case NorthWest:
                currentPosition.first -= maxHopDistance;
                currentPosition.second -= maxHopDistance;
                break;
        }
    }
    setPosition(currentPosition);
    currentPath.push_back(currentPosition);
    setPath(currentPath);
}

void Bishop::displayBug() {
    cout << getId() << " Bishop (" << getPosition().first << "," << getPosition().second << ") " << getSize() << " ";
    switch (getDirection()) {
        case NorthEast:
            cout << "NorthEast ";
            break;
        case SouthEast:
            cout << "SouthEast ";
            break;
        case SouthWest:
            cout << "SouthWest ";
            break;
        case NorthWest:
            cout << "NorthWest ";
            break;
    }
    cout << bisLength << " ";
    if (isAlive()) {
        cout << "Alive" << endl;
    } else {
        cout << "Dead" << endl;
    }
}

Bishop::~Bishop() {

}