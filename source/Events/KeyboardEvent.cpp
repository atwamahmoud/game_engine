//
// Created by atwa on 11/7/20.
//

#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent() = default;

int KeyboardEvent::addCallback(std::function<void(EntityManager &, int)> func) {
  this->callbacks[count] = func;
  return this->count++;
}

void KeyboardEvent::trigger(int key, EntityManager &manager) {
  for (std::pair<int, std::function<void(EntityManager &, int)>> element :
       this->callbacks) {
    element.second(manager, key);
  }
}

void KeyboardEvent::removeCallback(int i) { this->callbacks.erase(i); }
