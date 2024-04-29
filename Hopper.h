#ifndef CIARA_CLERKIN_CA2_HOPPER_H
#define CIARA_CLERKIN_CA2_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
protected:
    int hopLength;
public:
    Hopper(int id=0, std::pair<int, int> position={}, int direction=1, int size=1, int hopLength=2);
    void move();
    void outputBug();
    //std::string bugHistory();
    //void outputBugHistory();
    //bool isWayBlocked();
};

#endif


