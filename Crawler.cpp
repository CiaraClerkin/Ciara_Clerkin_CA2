#include "Crawler.h"
#include <iostream>

//Crawler::Crawler() = default;
using namespace std;

Crawler::Crawler (int id, pair<int, int> position, int direction, int size) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    //this->alive = true;
    this->path = {position};
    type = "Crawler";
}

void Crawler::move() {
    while (Bug::isWayBlocked()) {
        direction = (rand() % 4) + 1;
    }

    switch (direction) {
        //North
        case 1:
            position.second--;
            break;
        //East
        case 2:
            position.first++;
            break;
        //South
        case 3:
            position.second++;
            break;
        //West
        case 4:
            position.first--;
            break;
        default:
            break;
    }

    //cout << position.first << ", " << position.second << endl;

    path.emplace_back(position);
}

void Crawler::outputBug() {
    string status = "Alive";
    if (!alive) status = "Eaten by " + to_string(killerId);

    cout << id << " " << type << " (" << position.first << ", " << position.second << ") " << size << " " << direction << " " << status << endl;
}

/*string Crawler::bugHistory() {
    string final = to_string(id) + " Crawler Path: ";;

    for (list<pair<int, int>>::const_iterator it = path.cbegin(); it != path.cend(); ++it) {
        //cout << "(" << it->first << ", " << it->second << "), ";
        final += "(" + to_string(it->first) + ", " + to_string(it->second) + "), ";
    }

    string status = "Alive!";
    if (!alive) {
        // Where "Eaten by <id>" message will go
        status = "Dead!";
    }

    final += status + "\n";

    return final;
}

void Crawler::outputBugHistory() {
    cout << bugHistory();

    /*cout << id << " Crawler Path: ";


    for (list<pair<int, int>>::const_iterator it = path.cbegin(); it != path.cend(); ++it) {
        cout << "(" << it->first << ", " << it->second << "), ";
    }

    if (alive) {
        cout << "Alive!";
    }
    else {
        // Where "Eaten by <id>" message will go
        cout << "Dead!";
    }

    cout << endl;*/
//}