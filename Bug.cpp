#include "Bug.h"

#include <string>
//#include <list>
#include <utility>

//using namespace std;

//default constructor

Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
}

bool Bug::isWayBlocked() {
    int boardWidth = 10;
    int boardHeight = 10;

    switch(direction) {
        case 1:
            if (position.second <= 0) {
                return true;
            }
            break;
        case 2:
            if (position.first >= boardWidth) {
                return true;
            }
            break;
        case 3:
            if (position.second >= boardHeight) {
                return true;
            }
            break;
        case 4:
            if (position.first <= 0) {
                return true;
            }
            break;
        default:
            break;
    }

    return false;
}
