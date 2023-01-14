#include <iostream>
#include "Table.h"
#include "Node.h"

using namespace std;


int main() {

    auto table = new Table(9);

    table->setNode(Type::Blue, Size::Small, 1, 1);
    table->print();
    return 0;
}
