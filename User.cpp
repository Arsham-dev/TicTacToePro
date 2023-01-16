//
// Created by Mehr-systeM on 1/17/2023.
//

#include "User.h"


void User::setNode(Size size, int x, int y) {
    table->setNode(this->type, size, x, y);
    this->table->print();
}

User::User(Type type, Table &table) {
    this->numberOfLarge = 2;
    this->numberOfMedium = 2;
    this->numberOfSmall = 2;
    this->type = type;
    this->table = &table;
}

void User::setLargeNode(int x, int y) {
    if (this->numberOfLarge > 0) {
        setNode(Size::Large, x, y);
        this->numberOfLarge--;
    } else {

    }

}

void User::setMediumNode(int x, int y) {
    if (this->numberOfMedium > 0) {
        setNode(Size::Medium, x, y);
        this->numberOfMedium--;
    } else {

    }

}

void User::setSmallNode(int x, int y) {
    if (this->numberOfSmall > 0) {
        setNode(Size::Small, x, y);
        this->numberOfSmall--;
    } else {

    }

}
