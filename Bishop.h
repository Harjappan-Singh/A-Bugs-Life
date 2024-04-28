//
// Created by Harjappan Singh on 28/04/24.
//

#ifndef BUG_LIFE_PROJECT_BISHOP_H
#define BUG_LIFE_PROJECT_BISHOP_H


#include "Bug.h"

class Bishop : public Bug {
private:
    int bisLength;

public:
    Bishop();

    Bishop(int id, pair<int, int> position, Direction direction, int size, bool alive, int bisLength);

    int getBisLength() const;

    void setBisLength(int bisLength);

    void move() override;

    void displayBug() override;

    ~Bishop();

};


#endif //BUG_LIFE_PROJECT_BISHOP_H
