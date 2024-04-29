//
// Created by student on 29/04/2024.
//

#ifndef CIARA_CLERKIN_CA2_PATROLLER_H
#define CIARA_CLERKIN_CA2_PATROLLER_H

#include "Bug.h"

class Patroller : public Bug {
protected:
    int slideLength;
public:
    Patroller(int id=0, std::pair<int, int> position={}, int direction=1, int size=1);
    void move();
    void outputBug();
};


#endif //CIARA_CLERKIN_CA2_PATROLLER_H
