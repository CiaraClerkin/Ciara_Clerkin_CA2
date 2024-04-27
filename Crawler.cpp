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
    char type = 'C';
}

void Crawler::move() {
    while (Bug::isWayBlocked()) {
        direction = (rand() % 4) + 1;
    }

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

    //cout << position.first << ", " << position.second << endl;

    path.emplace_back(position);
}

void Crawler::outputBug() {
    string status = "Alive";
    if (!alive) {
        status = "Dead";
    }

    cout << id << " Crawler (" << position.first << ", " << position.second << ") " << size << " " << direction << " " << status << endl;
}