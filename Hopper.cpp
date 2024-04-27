#include "Hopper.h"

#include <iostream>

using namespace std;

Hopper::Hopper(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path, int hopLength) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    this->alive = alive;
    this->path = path;
    this->hopLength = hopLength; //range of 2-4 units
    char type = 'H';
};

void Hopper::move() {
    if (Bug::isWayBlocked()) {
        direction = (rand() % 4) + 1;
        //i = hopLength;
    }

    for (int i = 0; i < hopLength; i++) {
        if (Bug::isWayBlocked()) {
            i = hopLength;
        }
        else {
            switch (direction) {
                //North
                case 1:
                    position.second--;
                    break;
                    //East
                case 2:
                    position.first++;
                    break;
                    //South
                case 3:
                    position.second++;
                    break;
                    //West
                case 4:
                    position.first--;
                    break;
                default:
                    break;
            }
        }
    }

    path.emplace_back(position);
}

void Hopper::outputBug() {
    string status = "Alive";
    if (!alive) {
        status = "Dead";
    }

    cout << id << " Hopper (" << position.first << ", " << position.second << ") " << size << " " << direction << " " << hopLength << " " << status << endl;
}