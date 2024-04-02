#include <iostream>
#include <list>
using namespace std;

class Bug{
protected:
    int id;
    pair<int,int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int,int>> path;
    virtual void move() = 0;
    bool isWayBlocked(){};
};


class Crawler: public Bug{
public:
    void move(){

    }
};

class Hopper: public Bug{
    int hopLength;
public:
    void move(){

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
