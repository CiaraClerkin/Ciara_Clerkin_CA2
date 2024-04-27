#include <iostream>
#include <fstream>
#include<vector>
#include <sstream>
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

int main() {
    vector<Bug *> bugs;
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

        //cout << choice << endl;

        //switch (choice) {
            //case 1: {
            if (choice == 1) {
                ifstream fin("bugs.txt");
                string line = "";
                string value = "";
                vector<string> lines;

                char type;
                int id;
                int x;
                int y;
                pair<int, int> position;
                int direction;
                int size;
                bool alive;
                list<pair<int, int>> path;
                int hopLength;

                while (getline(fin, line)) {
                    lines.push_back(line);
                    //cout << line << endl;
                    //vect.push_back( new Crawler(0, {1, 7}, 4, 3, true, {}));
                }


                for (string l: lines) {
                    //cout << l << endl;
                    stringstream ss(l);
                    string value = "";
                    vector<string> values;

                    while (getline(ss, value, ';')) {
                        values.push_back(value);
                    }

                    type = *values[0].data();
                    id = stoi(values[1]);
                    x = stoi(values[2]);
                    y = stoi(values[3]);
                    direction = stoi(values[4]);
                    size = stoi(values[5]);

                    position.first = x;
                    position.second = y;

                    //cout << type << " " << id << " " << x << " " << y << " " << direction << " " << size;

                    //ss >> type >> id >> x >> y >> direction >> size;

                    if (type == 'H') {
                        hopLength = stoi(values[6]);
                        //cout << " " << hopLength;
                        bugs.push_back(new Hopper(id, position, direction, size, true, {}, hopLength));

                    } else {
                        bugs.push_back(new Crawler(id, position, direction, size, true, {}));
                    }

                    //cout << endl;
                    /*while (getline(ss, value, ';')) {
                        ss >> type >> id >> x >> y >> direction >> size;
                        /*ss >> type;
                        ss >> id;
                        ss >> x;
                        ss >> y;
                        ss >> direction;
                        ss >> size;*/
                    /*position.first = x;
                    position.second = y;
                    cout << type << " " << id << " " << x << " " << y << " " << direction << " " << size << endl;

                    if (type == 'H') {
                        ss >> hopLength;
                        int hopLength1 = hopLength;
                        bugs.push_back(new Hopper(id, position, direction, size, true, {}, hopLength1));
                    }
                    else {
                        bugs.push_back(new Crawler(id, position, direction, size, true, {}));
                    }*/


                    //>> position >> direction >> size >> alive >> path;
                }


                /*for (const auto & bug : bugs) {
                    //bug->move();
                    bug->outputBug();
                }

                cout << endl << "test of moving" << endl;

                for (int i = 0; i < 5; i++) {
                    for (const auto &bug: bugs) {
                        bug->move();
                        bug->outputBug();
                    }
                    cout << endl;
                }

                //stringstream ss(line);

                //for (int i = 0; i < )

                //while (getline(ss, value, ";")) {

                }*/
                //break;
            }
            //case 2: {
            else if (choice == 2) {
                cout << bugs.size() << endl;
                for (const auto &bug: bugs) {
                    //bug->move();
                    bug->outputBug();
                }
                break;
            }
                /*case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;*/
    }
    return 0;
}


/*void testing() {
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

    /*for (const auto & bug : vect) {
        bug->move();
        cout << bug->getPosition().first << ", " << bug->getPosition().second << endl;
    }*/

    //printing happens in crawler right now, fix that later.

    /*for (auto i : vect) {
        cout << i << ", " << i << endl;
    }*/
//}
