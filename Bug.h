#ifndef CIARA_CLERKIN_CA2_BUG_H
#define CIARA_CLERKIN_CA2_BUG_H

#include <string>
#include <utility>
#include <list>

using namespace std;

class Bug {
//private:


public:
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

    Bug();
    Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path);
    virtual void move();
    bool isWayBlocked(void);
};

#endif


