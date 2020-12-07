//
// Created by atwa on 11/7/20.
//

#include "MouseClick.h"

MouseClickEvent::MouseClickEvent() = default;

int MouseClickEvent::addCallback(std::function<void(EntityManager &, int)> func) {
  this->callbacks[count] = func;
  return this->count++;
}

void MouseClickEvent::trigger(int key, EntityManager &manager) {
  for (std::pair<int, std::function<void(EntityManager &, int)>> element :
       this->callbacks) {
    element.second(manager, key);
  }
}

void MouseClickEvent::removeCallback(int i) { this->callbacks.erase(i); }
