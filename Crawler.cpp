#include "Crawler.h"
#include <iostream>

//Crawler::Crawler() = default;
using namespace std;

Crawler::Crawler (int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    this->alive = alive;
    this->path = path;
}

void Crawler::move() {
    while (Bug::isWayBlocked()) {
        direction = (rand() % 4) + 1;
    }

    switch (direction) {
        case 1:
            position.second--;
            break;
        case 2:
            position.first++;
            break;
        case 3:
            position.second++;
            break;
        case 4:
            position.first--;
            break;
        default:
            break;
    }

    cout << position.first << ", " << position.second << endl;

    path.emplace_back(position);
}