#include "Hopper.h"

using namespace std;

Hopper::Hopper(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path, int hopLength) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    this->alive = alive;
    this->path = path;
    this->hopLength = hopLength; //range of 2-4 units
};

void Hopper::move() {
    for (int i = 0; i < hopLength; i++) {
        switch (direction) {
            case 1:  //
                position.second--;
                break;
            case 2:  //
                position.first++;
                break;
            case 3:  //
                position.first--;
                break;
            case 4: //
                position.second++;
                break;
            default:
                break;
        }

        if (Hopper::isWayBlocked()) {
            i = hopLength;
        }
    }

    path.emplace_back(position);
}