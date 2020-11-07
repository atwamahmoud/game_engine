//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_MOVEMENTSYSTEM_H
#define TEARS_ENGINE_MOVEMENTSYSTEM_H


#include "System.h"

class MovementSystem: public System {
    bool didSubscribe = false;
    void update(EntityManager&, EventManager&, double) override;
};


#endif //TEARS_ENGINE_MOVEMENTSYSTEM_H
