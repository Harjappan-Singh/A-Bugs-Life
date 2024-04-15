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


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
