//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_MOUSEMOVEEVENT_H
#define TEARS_ENGINE_MOUSEMOVEEVENT_H


#include "Event.h"
#include "../common.h"

struct MousePosition {
    float x;
    float y;
};

class MouseMoveEvent: private Event<MousePosition> {
    EVENTS name = MOUSE_MOVE;
public:
    MouseMoveEvent();
    void removeCallback(int);
    void trigger(MousePosition, EntityManager&);
    int addCallback(function<void(EntityManager &, MousePosition)>);
};


#endif //TEARS_ENGINE_MOUSEMOVEEVENT_H
