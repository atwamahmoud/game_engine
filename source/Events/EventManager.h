//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_EVENTMANAGER_H
#define TEARS_ENGINE_EVENTMANAGER_H

#include "Event.h"
#include "KeyboardEvent.h"
#include "MouseClick.h"
#include "MouseMoveEvent.h"
#include <vector>
class EventManager {

public:
  MouseMoveEvent mouseEvent = MouseMoveEvent();
  MousePosition mousePosition;
  KeyboardEvent keyboardEvent = KeyboardEvent();
  MouseClickEvent mouseClickEvent = MouseClickEvent();
};

#endif // TEARS_ENGINE_EVENTMANAGER_H
