#include <iostream>
#include "Table.h"
#include "Node.h"

using namespace std;


int main() {

    auto table = new Table(9);

    table->setNode(Type::Blue, Size::Small, 2, 1);
    table->setNode(Type::Blue, Size::Small, 2, 2);
    table->setNode(Type::Blue, Size::Small, 2, 3);
    table->print();
    table->checkGameIsEnd();
    return 0;
}
