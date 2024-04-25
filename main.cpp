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

    Crawler crawl = Crawler(0, {1, 2}, 5, 1, true, {});

    cout << crawl.getPosition().first << ", " << crawl.getPosition().second << endl;


    vector<Bug*> vect;   // vector of pointers to Bug objects
    vect.push_back( new Crawler(0, {1, 7}, 4, 3, true, {}));
    vect.push_back( new Hopper(1, {5, 5}, 1, 4, true, {}));

    /*for( Bug* bugPtr : vect) {
        bugPtr->move();
        cout << bugPtr->getPosition().first << ", " << bugPtr->getPosition().second << endl;
        //cout << bugPtr
    }*/

    for (const auto & bug : vect) {
        bug->move();
        cout << bug->getPosition().first << ", " << bug->getPosition().second << endl;
    }

    //printing happens in crawler right now, fix that later.

    /*for (auto i : vect) {
        cout << i << ", " << i << endl;
    }*/

    return 0;
}

