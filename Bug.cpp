#include "Bug.h"

#include <string>
//#include <list>
#include <utility>
#include <iostream>

using namespace std;

Bug::Bug(int id, pair<int, int> position, int direction, int size) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    alive = true;
    path = {position};
    killerId;
}

/*Bug::Bug(int id, std::pair<int, int> position, int direction, int size, bool alive,
         std::list<std::pair<int, int>> path) {

}*/

bool Bug::isWayBlocked() {
    int boardWidth = 10;
    int boardHeight = 10;

    switch(direction) {
        //North
        case 1:
            if (position.second <= 0) {
                return true;
            }
            break;
        //East
        case 2:
            if (position.first >= boardWidth) {
                return true;
            }
            break;
        //South
        case 3:
            if (position.second >= boardHeight) {
                return true;
            }
            break;
        //West
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

bool Bug::isIdSame(int id) {
    if (this->id == id) {
        return true;
    }
    else {
        return false;
    }
}

string Bug::bugHistory() {
    string final = to_string(id) + " " + type + " Path: ";;

    for (list<pair<int, int>>::const_iterator it = path.cbegin(); it != path.cend(); ++it) {
        //cout << "(" << it->first << ", " << it->second << "), ";
        final += "(" + to_string(it->first) + ", " + to_string(it->second) + "), ";
    }

    string status = "Alive!";
    if (!alive) {
        status = "Eaten by " + to_string(killerId);
    }

    final += status + "\n";

    return final;
}

void Bug::outputBugHistory() {
    cout << bugHistory();
}

bool Bug::isPositionSame(int x, int y) {
    if (x == position.first && y == position.second) {
        return true;
    }
    return false;
}

string Bug::getBasicDetails() {
    return type + " " + to_string(id);
}

int Bug::getId() {
    return id;
}

pair<int, int> Bug::getPosition() {
    return position;
}

int Bug::getDirection() {
    return direction;
}

int Bug::getSize() {
    return size;
}

bool Bug::isAlive() {
    return alive;
}

string Bug::getType() {
    return type;
}

std::list<std::pair<int, int>> Bug::getPath() {
    return path;
}

void Bug::die(int killerId) {
    alive = false;
    this->killerId = killerId;
}



