//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_EVENTMANAGER_H
#define TEARS_ENGINE_EVENTMANAGER_H


#include <vector>
#include "Event.h"
#include "MouseMoveEvent.h"
#include "ShapeChangeEvent.h"
class EventManager {

public:
    MouseMoveEvent mouseEvent = MouseMoveEvent();
    MousePosition mousePosition;
    int shape = 0;
    ShapeChangeEvent shapeChangeEvent = ShapeChangeEvent();
};



#endif //TEARS_ENGINE_EVENTMANAGER_H
