#ifndef CIARA_CLERKIN_CA2_BUG_H
#define CIARA_CLERKIN_CA2_BUG_H

#include <string>
#include <utility>
#include <list>


class Bug {
//private:


protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
    std::string type;
    int killerId;

public:
    //Bug();
    Bug(int id=0, std::pair<int, int> = {0, 0}, int direction=1, int size=1);
    virtual void move()=0;  /// "=0" makes a pure virtual function, so this becomes an abstract class (cant be instantiated)
    bool isWayBlocked();
    virtual void outputBug()=0;
    bool isIdSame(int id);
    std::string bugHistory();
    void outputBugHistory();
    bool isPositionSame(int x, int y);
    std::string getBasicDetails();

    int getId();
    std::pair<int, int> getPosition();
    int getDirection();
    int getSize();
    bool isAlive();
    std::string getType();
    std::list<std::pair<int, int>> getPath();
    void die(int killerId);

};

#endif


