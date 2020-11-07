//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_PROGRAMSYSTEM_H
#define TEARS_ENGINE_PROGRAMSYSTEM_H


#include "System.h"

class ProgramSystem: public System {
    bool didSubscribe = false;
public:
    void update(EntityManager&, EventManager&, double);
};


#endif //TEARS_ENGINE_PROGRAMSYSTEM_H
