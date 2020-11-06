//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#include "EntityManager.h"

Entity* EntityManager::createEntity() {
    Entity* entity = new Entity();
    entity->id = count++;
    this->entities.push_back(entity);
    return entity;
}


//Needs some refactoring to decrease complexity, O(n*m)
std::vector<Entity*> EntityManager::getEntitiesHaving(std::vector<std::string> names) {
    std::vector<Entity*> entities = {};
    //Used reserve() to make sure push_back is O(1)
    entities.reserve(this->entities.size());

    for (int i = 0; i < this->entities.size(); i++) {

        auto components = this->entities[i]->components;
        bool found = true;

        for(int j = 0; j < names.size(); j++) {
            //Find should be O(1)
            if(components.find(names[i]) == components.end()) {
                found = false;
                break;
            }

        }

        if(found) entities.push_back(this->entities[i]);
    }
    return entities;
}

