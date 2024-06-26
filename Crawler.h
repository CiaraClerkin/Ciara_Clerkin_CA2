#ifndef CIARA_CLERKIN_CA2_CRAWLER_H
#define CIARA_CLERKIN_CA2_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {    // Crawler inherits from Bug.. It is a subclass
public:

    Crawler(int id=0, std::pair<int, int> position={0, 0}, int direction=1, int size=1);
    void move();
    void outputBug();
    //std::string bugHistory();
    //void outputBugHistory();
    //bool isWayBlocked();
};

#endif


