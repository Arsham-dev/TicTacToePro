#include <iostream>
#include "Table.h"
#include "Node.h"
#include "User.h"

using namespace std;


int main() {
    auto table = Table(9);
    auto user1 = new User(Type::Blue, table);
    auto user2 = new User(Type::Red, table);

    return 0;
}
