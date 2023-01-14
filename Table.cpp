//
// Created by Mehr-systeM on 1/14/2023.
//

#include "Table.h"
#include <iostream>

using namespace std;

Table::Table(int length) {
    this->length = length;
    this->nodes = new vector<Node>[length];
}

void Table::setNode(Type type, Size size, int x, int y) {
    Node node = {type, size};
    const int row = 3;
    const int index = (x - 1) * row + y - 1;
    this->nodes[index].push_back(node);
}

void Table::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "| ";
            const int index = i * 3 + j;
            const auto data = nodes[index];
            if (data.empty())
                cout << "   ";
            else
                cout << showUpperNode(nodes[index]) << " ";
        }
        cout << "|" << endl;
    }
}

std::string Table::showUpperNode(std::vector<Node> node) {
    if (node.empty()) {
        return " ";
    }
    Node answer = node[0];
    for (auto &n: node)
        if (n.size > answer.size)
            answer = n;

    if (answer.type == Type::Blue)
        return "B" + to_string(answer.size + 1);
    else
        return "R" + to_string(answer.size + 1);


}



