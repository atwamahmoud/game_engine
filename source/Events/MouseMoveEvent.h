//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_MOUSEMOVEEVENT_H
#define TEARS_ENGINE_MOUSEMOVEEVENT_H


#include "Event.h"
#include "../common.h"

struct MousePosition {
    int x;
    int y;
};

class MouseMoveEvent: public Event<MousePosition> {
    EVENTS name = MOUSE_MOVE;
public:
    MouseMoveEvent();
};


#endif //TEARS_ENGINE_MOUSEMOVEEVENT_H
