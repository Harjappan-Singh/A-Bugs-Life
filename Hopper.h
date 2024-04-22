//
// Created by Harjappan Singh on 22/04/24.
//

#ifndef BUG_LIFE_PROJECT_HOPPER_H
#define BUG_LIFE_PROJECT_HOPPER_H

#include "Bug.h"
class Hopper: public Bug{
private:
    int hopLength;
public:
    Hopper();
    Hopper(int id, pair<int, int> position, Direction direction, int size, bool alive, int hopLength);

    int getHopLength() const;

    void setHopLength(int hopLength);

    void move() override;

    void displayBug() override;

    ~Hopper();
};


#endif //BUG_LIFE_PROJECT_HOPPER_H
