#include <iostream>
#include <fstream>
#include<vector>
#include <sstream>
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

int main() {
    int choice = 0;

    while (choice != 8) {
        cout << "1. Initialize Bug Board (load data from file)" << endl;
        cout << "2. Display all Bugs" << endl;
        cout << "3. Find a Bug (given an id)" << endl;
        cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
        cout << "5. Display Life History of all Bugs (path taken)" << endl;
        cout << "6. Display all Cells listing their Bugs" << endl;
        cout << "7. Run simulation (generates a Tap every second)" << endl;
        cout << "8. Exit (write Life History of all Bugs to file)" << endl;

        cin >> choice;

        vector<Bug*> vect;

        //cout << choice << endl;

        switch (choice) {
            case 1:
                ifstream fin("input.txt");
                string line = "";
                string value = "";
                vector<string> lines;

                while (getline(fin, line)) {
                    lines.push_back(line);
                    //vect.push_back( new Crawler(0, {1, 7}, 4, 3, true, {}));
                }

                //stringstream ss(line);

                //for (int i = 0; i < )

                //while (getline(ss, value, ";")) {

                //}
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
        }
    }

    return 0;
}

void testing() {
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
}
