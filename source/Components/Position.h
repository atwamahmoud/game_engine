//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_POSITION_H
#define TEARS_ENGINE_POSITION_H


#include "Component.h"

class Position: public Component {
public:
    float x = 0;
    float y = 0;
    ~Position();
};


#endif //TEARS_ENGINE_POSITION_H
