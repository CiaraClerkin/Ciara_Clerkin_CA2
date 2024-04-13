#include "Bug.cpp"

class Crawler: public Bug {

};

void Bug::move() {
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

    path.emplace_back(position);
}