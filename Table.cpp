//
// Created by Mehr-systeM on 1/14/2023.
//

#include "Table.h"

using namespace std;

Table::Table(int length) {
    this->length = length;
    this->nodes = new vector<Node>[length];
}

void Table::setNode(Type type, Size size, int x, int y) {
    Node node = {type, size};
    const int row = 3;
    const int index = (x - 1) * row + y;
    this->nodes[index].push_back(node);
}



