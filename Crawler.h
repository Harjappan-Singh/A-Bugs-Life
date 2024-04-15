//
// Created by Harjappan Singh on 15/04/24.
//

#ifndef BUG_LIFE_PROJECT_CRAWLER_H
#define BUG_LIFE_PROJECT_CRAWLER_H


#include "Bug.h"

class Crawler: public Bug{
public:
    Crawler(int id, pair<int, int> position, enum direction direction, int size, bool alive);
    void move() override;
};


#endif //BUG_LIFE_PROJECT_CRAWLER_H
