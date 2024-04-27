#ifndef CIARA_CLERKIN_CA2_HOPPER_H
#define CIARA_CLERKIN_CA2_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;
public:
    Hopper(int id=0, std::pair<int, int> position={}, int direction=1, int size=1, bool alive=true, std::list<std::pair<int, int>> path = {}, int hopLength=2);
    void move();
    void outputBug();
    void outputBugHistory();
    //bool isWayBlocked();
};

#endif


