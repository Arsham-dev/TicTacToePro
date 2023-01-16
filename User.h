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

public:
    User(Type type, Table &table);

    void setLargeNode(int x, int y);

    void setMediumNode(int x, int y);

    void setSmallNode(int x, int y);
};


#endif //UNTITLED_USER_H
