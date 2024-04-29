//
// Created by student on 29/04/2024.
//

#include "Patroller.h"

#include <iostream>

using namespace std;

Patroller::Patroller(int id, pair<int, int> position, int direction, int size) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    //alive = true;
    path = {position};
    this->slideLength = slideLength; //range of 2-4 units
    type = "Patroller";
};

void Patroller::move() {
    if (Bug::isWayBlocked()) {
        direction = (rand() % 4) + 1;
        //i = hopLength;
    }

    switch (direction) {
        //North
        case 1:
            position.second--;
            if (Bug::isWayBlocked()) direction = 3;
            break;
            //East
        case 2:
            position.first++;
            if (Bug::isWayBlocked()) direction = 4;
            break;
            //South
        case 3:
            position.second++;
            if (Bug::isWayBlocked()) direction = 1;
            break;
            //West
        case 4:
            position.first--;
            if (Bug::isWayBlocked()) direction = 2;
            break;
        default:
            break;
    }

    path.emplace_back(position);
}

void Patroller::outputBug() {
    string status = "Alive";
    if (!alive) status = "Dead";

    cout << id << " " << type << " (" << position.first << ", " << position.second << ") " << size << " " << direction << " " << status << endl;
}


