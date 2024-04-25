#include <iostream>
#include<vector>
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

//    Crawler c;
//    //Bug b(0, 5, 5, 1, 2);
//
//    c.id = 0;
//    c.position.first = 5;
//    c.position.second = 5;
//    c.direction = 1;
//    c.size = 2;
    //c.path = {};

    vector<Bug*> vect(10);   // vector of pointers to Bug objects
    vect.push_back( new Crawler(0, pair(5, 5), 5, 1, 2, {}));
    //vect.push_back( new Hopper( sss,s,s,s,));

    for( Bug* bugPtr : vect) {
        bugPtr->move();
        cout << bugPtr->getPosition().first << ", " << bugPtr->getPosition().second << endl;
        //cout << bugPtr
    }

    //printing happens in crawler right now, fix that later.

    /*for (auto i : vect) {
        cout << i << ", " << i << endl;
    }*/

    return 0;
}

