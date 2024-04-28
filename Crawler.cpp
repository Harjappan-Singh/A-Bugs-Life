//
// Created by Harjappan Singh on 15/04/24.
//
#include <iostream>
#include <ctime>
#include "Crawler.h"

Crawler::Crawler() : Bug() {
}

Crawler::Crawler(int id, pair<int, int> position, Direction direction, int size, bool alive) : Bug(id, position, direction, size, alive) {
}


void Crawler::move(){
    pair<int, int> currentPosition = getPosition();
    Direction currentDirection = getDirection();
    list<pair<int, int>> currentPath = getPath();

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
        addPath(currentPosition);
    } else {
        int newDirection = rand() % 4 + 1;
        setDirection((Direction) newDirection);
        move();
    }
}

void Crawler::displayBug() {
    cout << getId() << " Crawler (" << getPosition().first << "," << getPosition().second << ") " << getSize() << " ";
    switch (getDirection()) {
        case North:
            cout << "North ";
            break;
        case South:
            cout << "South ";
            break;
        case East:
            cout << "East ";
            break;
        case West:
            cout << "West ";
            break;
    }
    if (isAlive()) {
        cout << "Alive" << endl;
    } else {
        cout << "Dead" << endl;
    }
}

Crawler::~Crawler() {

}