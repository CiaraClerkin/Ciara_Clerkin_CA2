#include "Bug.h"

#include <string>
//#include <list>
#include <utility>

//using namespace std;

Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
}

void Bug::move() {

}

bool Bug::isWayBlocked() {
    int boardWidth = 10;
    int boardHeight = 10;

    switch(direction) {
        case 1:
            if (position.second - 1 == 0) {
                return true;
            }
            break;
        case 2:
            if (position.first -1 == 0) {
                return true;
            }
            break;
        case 3:
            if (position.second + 1 == boardHeight) {
                return true;
            }
            break;
        case 4:
            if (position.first + 1 == boardWidth) {
                return true;
            }
            break;
        default:
            break;
    }

    return false;
}
