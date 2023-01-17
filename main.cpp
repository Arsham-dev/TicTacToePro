#include <iostream>
#include "Table.h"
#include "Node.h"
#include "User.h"

using namespace std;


string getCommand();

int getSizeOfNode();

int getLocation(bool isX);

bool runCommand(const string &command, User *&user);

int main() {
    auto table = new Table(9);
    User *user1 = new User(Type::Blue, table);
    User *user2 = new User(Type::Red, table);

    while (true) {
        cout << "User one turn\n";
        bool checkUser1 = true;
        do {
            if (!checkUser1) {
                cout << "An error happened\nPlease try again\n";
            }
            string command = getCommand();
            checkUser1 = runCommand(command, user1);
        } while (!checkUser1);
        user1->print();
        string checkResult = table->checkGameIsEnd();
        if (checkResult == "B" || checkResult == "R") {
            if (checkResult == "B")
                cout << "Blue player is winner";
            else {
                cout << "Red player is winner";
            }
            break;
        }

        cout << "User two turn\n";

        bool checkUser2 = true;
        do {
            if (!checkUser2) {
                cout << "An error happened\nPlease try again\n";
            }
            string command = getCommand();
            checkUser2 = runCommand(command, user2);
        } while (!checkUser2);
        user2->print();
        checkResult = table->checkGameIsEnd();
        if (checkResult == "B" || checkResult == "R") {
            if (checkResult == "B")
                cout << "Blue player is winner";
            else {
                cout << "Red player is winner";
            }
            break;
        }
    }

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
            return to_string(sizeOfNode) + " " + to_string(xPast) + " " + to_string(yPast) + " "
                   + to_string(x) + " " + to_string(y);
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

bool runCommand(const string &command, User *&user) {
    int sizeNumber = stoi(command.substr(0, 1));
    if (command.length() == 5) {
        const int x = stoi(command.substr(2, 1));
        const int y = stoi(command.substr(4, 1));
        switch (sizeNumber) {
            case 1:
                return user->setSmallNode(x, y);
            case 2:
                return user->setMediumNode(x, y);
            case 3:
                return user->setLargeNode(x, y);
            default:
                return false;
        }
    } else {
        const int xPast = stoi(command.substr(2, 1));
        const int yPast = stoi(command.substr(4, 1));
        const int x = stoi(command.substr(6, 1));
        const int y = stoi(command.substr(8, 1));

        switch (sizeNumber) {
            case 1:
                return user->moveSmallNode(xPast, yPast, x, y);
            case 2:
                return user->moveMediumNode(xPast, yPast, x, y);
            case 3:
                return user->moveLargeNode(xPast, yPast, x, y);
            default:
                return false;
        }
    }
}