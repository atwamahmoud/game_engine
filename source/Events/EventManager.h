//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_EVENTMANAGER_H
#define TEARS_ENGINE_EVENTMANAGER_H

#include "Event.h"
#include "KeyboardEvent.h"
#include "MouseClickEvent.h"
#include "MouseMoveEvent.h"
#include <vector>

class EventManager {

public:
  MouseMoveEvent mouseEvent = MouseMoveEvent();
  MouseClickEvent mouseClickEvent = MouseClickEvent();
  MousePosition mousePosition;
  KeyboardEvent keyboardEvent = KeyboardEvent();
};

#endif // TEARS_ENGINE_EVENTMANAGER_H
