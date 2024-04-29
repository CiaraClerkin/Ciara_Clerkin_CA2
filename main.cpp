#include <iostream>
#include <fstream>
#include<vector>
#include <sstream>
#include "Crawler.h"
#include "Hopper.h"
#include "Patroller.h"
//#include <windows.h>
#include <unistd.h>

using namespace std;

vector<Bug *> bugs;

void feature1() {
    //if (choice == 1) {
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
            bugs.push_back(new Hopper(id, position, direction, size, hopLength));

        } else if (type == 'C'){
            bugs.push_back(new Crawler(id, position, direction, size));
        }
        else if (type == 'P') {
            bugs.push_back(new Patroller(id, position, direction, size));
        }
    }
}

void feature2() {
    for (const auto &bug: bugs) {
        //bug->move();
        bug->outputBug();
    }
}

void feature3() {
    int id;
    bool bugFound;
    cout << "Enter id: ";
    cin >> id;
    cout << endl;

    for (const auto &bug: bugs) {
        if (bug->isIdSame(id)) {
            bugFound = true;
            bug->outputBug();
            break;
        }
    }

    if (!bugFound) {
        cout << "bug " << id << " not found";
    }
}

void feature4() {
    for (const auto &bug: bugs) {
        if (bug->isAlive()) bug->move();
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            vector<Bug *> samesies;
            //vector<Bug *> bugsSameCell;
            bool bugFound = false;
            for (const auto &bug: bugs) {
                if (bug->isAlive()) {
                    bugFound = true;
                    if (bug->isPositionSame(i, j)) {
                        samesies.push_back(bug);
                    }
                }
            }

            int bigBugId = 0;
            int max = 0;

            for (const auto &bug: samesies) {
                int size = bug->getSize();
                if (size > max) {
                    max = size;
                    bigBugId = bug->getId();
                }

                //for (const auto &bug: pair.second) {
                //}
            }

            for (const auto &bug: samesies) {
                if (bug->getId() != bigBugId) {
                    bug->die(bigBugId);
                }
            }

            /*if (bugFound) {
                samesies.push_back(pair<pair<int, int>, vector<Bug *>>(pair<int, int>(i, j), bugsSameCell));
            }*/
        }
    }
}

void feature5() {
    for (const auto &bug: bugs) {
        bug->outputBugHistory();
    }
}

void feature6(string filename) {
    ofstream fout(filename + ".txt");
    for (const auto &bug: bugs) {
        fout << bug->bugHistory();
    }
}

void feature7() {
    //board with and height of 10
    for (int i = 0; i < 10; i++) {
        for (int j =0; j < 10; j++) {
            cout << "(" << i << ", " << j << ") ";

            bool bugFound = false;
            for (const auto& bug : bugs) {
                if (bug->isPositionSame(i, j)) {
                    bugFound = true;
                    cout << bug->getBasicDetails() << ", ";
                }
            }

            if (!bugFound) cout << "empty";
            cout << endl;
        }
    }
}

void feature9() {
    bool game = true;

    while (game) {
        sleep(1);  //https://www.geeksforgeeks.org/sleep-function-in-cpp/
        feature4();
        feature2();
        cout << endl;

        vector<Bug*> survivingBugs;
        for (const auto &bug : bugs) {
            if (bug->isAlive()) survivingBugs.push_back(bug);
        }

        if (survivingBugs.size() == 1) {
            game = false;
            cout << "Game over! " << survivingBugs[0]->getType() << " " << survivingBugs[0]->getId() << " wins!" ;
            feature6("Simulation");
        }
    }
}



int main() {
    int choice = 0;
    //list<pair<pair<int, int>, vector<Bug *>>> samesies;

    while (choice != 8) {
        cout << endl << "1. Initialize Bug Board (load data from file)" << endl;
        cout << "2. Display all Bugs" << endl;
        cout << "3. Find a Bug (given an id)" << endl;
        cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
        cout << "5. Display Life History of all Bugs (path taken)" << endl;
        cout << "6. Display all Cells listing their Bugs" << endl;
        cout << "7. Run simulation (generates a Tap every second)" << endl;
        cout << "8. Exit (write Life History of all Bugs to file)" << endl;

        cin >> choice;

        //cout << choice << endl;

        switch (choice) {
            case 1: {
                feature1();
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
                //}


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
                break;
            }
            case 2: {
                feature2();
                break;
            }
            case 3: {
                feature3();
                break;
            }
            case 4:
                feature4();
                break;
            case 5:
                feature5();
                break;
            case 6:
                feature7();
                break;
            case 7:
                feature9();
                break;
            case 8:
                feature6("Bug History");
                break;
        }
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
