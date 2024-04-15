//
// Created by Harjappan Singh on 15/04/24.
//
#include <iostream>
#include <ctime>
#include "Crawler.h"


Crawler::Crawler(int id, pair<int, int> position, enum direction direction, int size, bool alive) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
}

void Crawler::move(){
//    if bug pointing at a direction which is blocked
// then generate a random direction and set that direction to the current direction of bug

// so if the bug is pointing to
// assume that bug is at (5,4)
// North -> move the bug towards north so decrease the y part by one (5,3)
// East -> move the bug towards east so increase the x part by one (6,  4)
// South -> move the bug towards south so increase the y part by one (5,5)
// West -> move the bug towards west so decrease the x part by one (3,4)

    srand(time(0));
    enum direction newDirection;
 while(this->isWayBlocked()){
     int randomNum =  rand() % 4+1;
     if(randomNum == 1){
         newDirection = North;
     } else if (randomNum == 2){
         newDirection = East;
     }else if (randomNum == 3){
         newDirection = South;
     }else if (randomNum == 4){
         newDirection = West;
     }
      this->direction = newDirection;
 }

    if(this->direction == North){
        this->position.second-= 1;
    } else if(this->direction == East){
        this->position.first+= 1;
    } else if (this->direction == South){
        this->position.second+= 1;
    } else if (this->direction == West){
        this->position.first-= 1;
    }

    this->path.push_back(this->position);
}

//;put srand in main