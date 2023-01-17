#include <iostream>
#include "Table.h"
#include "Node.h"
#include "User.h"

using namespace std;


string getCommand();

int getSizeOfNode();

int getLocation(bool isX);

int main() {
    Table table = *new Table(9);
    User user1 = *new User(Type::Blue, table);
    User user2 = *new User(Type::Red, table);

    cout << getCommand();

    return 0;
}

string getCommand() {
    cout << "Please Enter user move\n1-Set Node\n2-Move Node\n";
    while (true) {
        string firstCommand;
        cin >> firstCommand;
        if (firstCommand == "1") {
            int sizeOfNode = getSizeOfNode();
            int x = getLocation(true);
            int y = getLocation(false);
            return to_string(sizeOfNode) + " " + to_string(x) + " " + to_string(y);
        } else if (firstCommand == "2") {
            int sizeOfNode = getSizeOfNode();
            cout << "First enter current node location" << endl;
            int xPast = getLocation(true);
            int yPast = getLocation(false);
            cout << "Now enter new location" << endl;
            int x = getLocation(true);
            int y = getLocation(true);
            return to_string(sizeOfNode) + " " + to_string(xPast) + " " + to_string(yPast)
                   + to_string(x) + " " + to_string(y);;
        } else {
            cout << "Please Enter an valid Command\n1-Set Node\n2-Move Node\n";
        }
    }
}

int getSizeOfNode() {
    string sizeOfNode;
    cout << "Enter Size of Node\n1-Small\n2-Medium\n3-Large\n";
    while (true) {
        cin >> sizeOfNode;
        if (sizeOfNode == "1" || sizeOfNode == "2" || sizeOfNode == "3")
            return stoi(sizeOfNode);
        else {
            cout << "Enter a valid size\n1-Small\n2-Medium\n3-Large\n";
        }
    }
}

int getLocation(bool isX) {
    string number;
    if (isX) {
        cout << "Enter X" << endl;
    } else {
        cout << "Enter Y" << endl;
    }
    while (true) {
        cin >> number;
        if (number == "1" || number == "2" || number == "3") {
            return stoi(number);
        } else {
            cout << "Enter a number between 1 and 3" << endl;
        }
    }

}