//
// Created by Mehr-systeM on 1/14/2023.
//

#ifndef UNTITLED_TABLE_H
#define UNTITLED_TABLE_H

#include "Node.h"
#include <vector>

class Table {
private:
    std::vector<Node> *nodes;
    int length;
public:
    Table(int length);

    void setNode(Type type, Size size, int x, int y);

};


#endif //UNTITLED_TABLE_H
