//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_SYSTEMMANAGER_H
#define TEARS_ENGINE_SYSTEMMANAGER_H


#include <unordered_map>
#include "../Events/EventManager.h"
#include "System.h"

class SystemManager {
    EventManager* eventManager;
    EntityManager* entityManager;
    vector<System*> systems;
public:
    SystemManager(EventManager*, EntityManager*);
    void init();
    void update(double);
};


#endif //TEARS_ENGINE_SYSTEMMANAGER_H
