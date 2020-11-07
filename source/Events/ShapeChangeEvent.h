//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_SHAPECHANGEEVENT_H
#define TEARS_ENGINE_SHAPECHANGEEVENT_H


#include "../common.h"
#include "Event.h"


class ShapeChangeEvent : private Event<int> {
    EVENTS name = MOUSE_MOVE;
public:
    ShapeChangeEvent();
    void removeCallback(int);
    void trigger(int, EntityManager&);
    int addCallback(function<void(EntityManager &, int)>);
};


#endif //TEARS_ENGINE_SHAPECHANGEEVENT_H
