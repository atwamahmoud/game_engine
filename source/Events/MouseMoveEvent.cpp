//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#include "MouseMoveEvent.h"

#include <utility>

MouseMoveEvent::MouseMoveEvent() = default;

int MouseMoveEvent::addCallback(std::function<void(EntityManager &, MousePosition)> func) {
    this->callbacks[count] = func;
    return this->count++;
}

void MouseMoveEvent::trigger(MousePosition pos, EntityManager & manager) {
    for(std::pair<int, std::function<void(EntityManager&, MousePosition)>> element: this->callbacks) {
        element.second(manager, pos);
    }
}

void MouseMoveEvent::removeCallback(int i) {
    this->callbacks.erase(i);
}


