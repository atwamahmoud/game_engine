//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_ENTITYMANAGER_H
#define TEARS_ENGINE_ENTITYMANAGER_H

#include <unordered_map>
#include <typeinfo>
#include <vector>
#include "Entity.h"
#include "../common.h"

class EntityManager {
    int size = 0;
    int count = 0;
    std::vector<Entity*> entities = {};
public:
    Entity* createEntity();
    std::vector<Entity*> getEntitiesHaving(std::vector<std::string>);
};


#endif //TEARS_ENGINE_ENTITYMANAGER_H
