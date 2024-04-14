#include <iostream>

#include "Bug.cpp"
#include "Crawler.cpp"
#include "Hopper.cpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Crawler c;

    c.id = 0;
    c.position.first = 5;
    c.position.second = 5;
    c.direction = 1;
    c.size = 2;
    //c.path = {};

    for (int i = 0; i < 20; i++) {
        c.move();
    }

    for (auto i : c.path) {
        cout << i.first << ", " << i.second << endl;
    }

    return 0;
}

