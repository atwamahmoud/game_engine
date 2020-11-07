//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_ENTITY_H
#define TEARS_ENGINE_ENTITY_H


#include <unordered_map>
#include "../common.h"
#include "../Components/Component.h"

class Entity {
    friend class EntityManager;
    Entity();
    int id;
public:
    std::unordered_map<std::string, Component*> components;
    void addComponent(Component*, string);
    void removeComponent(std::string);
    int getId();
    ~Entity();
};


#endif //TEARS_ENGINE_ENTITY_H
