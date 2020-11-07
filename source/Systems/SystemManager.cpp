//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#include "SystemManager.h"
#include "MovementSystem.h"

SystemManager::SystemManager(EventManager * eventManager, EntityManager * entityManager) {
    this->eventManager = eventManager;
    this->entityManager = entityManager;
}

void SystemManager::init() {
    this->systems.push_back(new MovementSystem());
}

void SystemManager::update(double dt) {
    for (int i = 0; i < this->systems.size(); i++) {
        this->systems[i]->update(*entityManager, *eventManager, dt);
    }
}
