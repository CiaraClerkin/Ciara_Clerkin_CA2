#ifndef CIARA_CLERKIN_CA2_HOPPER_H
#define CIARA_CLERKIN_CA2_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;
public:
    Hopper(int hopLength);
    void move();
    //bool isWayBlocked();
};

#endif


