//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_MOUSE_CLICK_H
#define TEARS_ENGINE_MOUSE_CLICK_H

#include "../common.h"
#include "Event.h"

class MouseClickEvent : private Event<int> {
  EVENTS name = KEYBOARD;

public:
  MouseClickEvent();
  void removeCallback(int);
  void trigger(int, EntityManager &);
  int addCallback(function<void(EntityManager &, int)>);
};

#endif // TEARS_ENGINE_MOUSE_CLICK_H
