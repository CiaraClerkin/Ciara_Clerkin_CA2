#include "Bug.h"

#include <string>
//#include <list>
#include <utility>
#include <iostream>

using namespace std;

Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    this->alive = alive;
    this->path = path;
}

/*Bug::Bug(int id, std::pair<int, int> position, int direction, int size, bool alive,
         std::list<std::pair<int, int>> path) {

}*/

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

pair<int, int> Bug::getPosition() {
    return position;
}



