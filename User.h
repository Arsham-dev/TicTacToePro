//
// Created by Mehr-systeM on 1/17/2023.
//

#ifndef UNTITLED_USER_H
#define UNTITLED_USER_H

#include "Node.h"
#include "Table.h"

class User {
private:
    int numberOfLarge;
    int numberOfMedium;
    int numberOfSmall;
    Type type;
    Table *table;

    void setNode(Size size, int x, int y);

    bool moveNode(Size size, int pastX, int pastY, int x, int y);

public:
    User(Type type, Table *&table);

    bool setLargeNode(int x, int y);

    bool setMediumNode(int x, int y);

    bool setSmallNode(int x, int y);

    bool moveLargeNode(int pastX, int pastY, int x, int y);

    bool moveMediumNode(int pastX, int pastY, int x, int y);

    bool moveSmallNode(int pastX, int pastY, int x, int y);

    void print();


};


#endif //UNTITLED_USER_H
