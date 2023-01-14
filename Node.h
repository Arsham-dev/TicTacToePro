//
// Created by Mehr-systeM on 1/14/2023.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

enum Type {
    Red = 0,
    Blue = 1
};

enum Size {
    Small = 0,
    Medium = 1,
    Large = 2
};

struct Node {
    Type type;
    Size size;
};

#endif //UNTITLED_NODE_H
