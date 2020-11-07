//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#include "Entity.h"

void Entity::addComponent(Component* component, string name) {
    //Doesn't use [] operator to prevent adding new element
    //See: http://www.cplusplus.com/reference/unordered_map/unordered_map/operator[]/
    if(this->components.find(name) != this->components.end()) {
        throw invalid_argument("Components with the same name already exists");
    }
    this->components[name] = component;
}

void Entity::removeComponent(std::string name) {
    this->components.erase(name);
}

int Entity::getId() {
    return id;
}

Entity::Entity() {
}


Entity::~Entity() {
    auto iterator = this->components.begin();
    for(; iterator != this->components.end(); ++iterator) {
        delete iterator->second;
    }
}
