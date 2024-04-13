#include "Hopper.h"

Hopper::Hopper(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path, int hopLength) {
    private:
        int hopLength; //range of 2-4 units
};

void Bug::move() {
    for (int i = 0; i < hopLength; i++) {
        switch (direction) {
            case 1:
                position.second--;
                break;
            case 2:
                position.first++;
                break;
            case 3:
                position.first--;
                break;
            case 4:
                position.second++;
                break;
            default:
                break;
        }

        if (Bug::isWayBlocked()) {
            i = hopLength;
        }
    }

    path.emplace_back(position);
}