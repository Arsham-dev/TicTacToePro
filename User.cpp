//
// Created by Mehr-systeM on 1/17/2023.
//

#include <iostream>
#include "User.h"


void User::setNode(Size size, int x, int y) {
    this->table->print();
    const auto isEnded = this->table->checkGameIsEnd();
    if (isEnded == "R" || isEnded == "B") {
        std::cout << isEnded << " Is Winner" << std::endl;
    }
}

User::User(Type type, Table &table) {
    this->numberOfLarge = 2;
    this->numberOfMedium = 2;
    this->numberOfSmall = 2;
    this->type = type;
    this->table = &table;
}

bool User::setLargeNode(int x, int y) {
    if (this->numberOfLarge > 0) {
        setNode(Size::Large, x, y);
        this->numberOfLarge--;
        return true;
    } else {
        return false;
    }

}

bool User::setMediumNode(int x, int y) {
    if (this->numberOfMedium > 0) {
        setNode(Size::Medium, x, y);
        this->numberOfMedium--;
        return true;
    } else {
        return false;
    }

}

bool User::setSmallNode(int x, int y) {
    if (this->numberOfSmall > 0) {
        setNode(Size::Small, x, y);
        this->numberOfSmall--;
        return true;
    } else {
        return false;
    }

}

void User::moveNode(Size size, int pastX, int pastY, int x, int y) {
    this->table->moveNode(this->type, size, pastX, pastY, x, y);
    this->table->print();

    const auto isEnded = this->table->checkGameIsEnd();
    if (isEnded == "R" || isEnded == "B") {
        std::cout << isEnded << " Is Winner" << std::endl;
    }
}

void User::moveLargeNode(int pastX, int pastY, int x, int y) {
    moveNode(Size::Large, pastX, pastY, x, y);
}

void User::moveMediumNode(int pastX, int pastY, int x, int y) {
    moveNode(Size::Medium, pastX, pastY, x, y);
}

void User::moveSmallNode(int pastX, int pastY, int x, int y) {
    moveNode(Size::Small, pastX, pastY, x, y);
}
