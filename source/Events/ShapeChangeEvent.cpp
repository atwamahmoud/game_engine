//
// Created by atwa on 11/7/20.
//

#include "ShapeChangeEvent.h"

ShapeChangeEvent::ShapeChangeEvent() = default;

int ShapeChangeEvent::addCallback(std::function<void(EntityManager &, int)> func) {
    this->callbacks[count] = func;
    return this->count++;
}

void ShapeChangeEvent::trigger(int shape, EntityManager & manager) {
    for(std::pair<int, std::function<void(EntityManager&, int)>> element: this->callbacks) {
        element.second(manager, shape);
    }
}

void ShapeChangeEvent::removeCallback(int i) {
    this->callbacks.erase(i);
}
