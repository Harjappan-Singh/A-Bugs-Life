//
// Created by Harjappan Singh on 15/04/24.
//
#include <iostream>
#include <ctime>
#include "Crawler.h"

Crawler::Crawler() : Bug() {

}

Crawler::Crawler(int id, pair<int, int> position, enum direction direction, int size, bool alive) : Bug(id, position, direction, size, alive) {
}


void Crawler::move(){
    pair<int, int> currentPosition = getPosition();
    enum direction currentDirection = getDirection();
    list<std::pair<int, int>> currentPath = getPath();

    if (!isWayBlocked()) {
        switch (currentDirection) {
            case North:
                currentPosition.second -= 1;
                break;
            case South:
                currentPosition.second += 1;
                break;
            case East:
                currentPosition.first += 1;
                break;
            case West:
                currentPosition.first -= 1;
                break;
        }
        setPosition(currentPosition);
        currentPath.push_back(currentPosition);
        setPath(currentPath);
    } else {
        int newDirection = rand() % 4 + 1;
        setDirection((enum direction) newDirection);
        move();
    }
}

Crawler::~Crawler() {

}