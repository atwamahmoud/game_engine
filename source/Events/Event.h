//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_EVENT_H
#define TEARS_ENGINE_EVENT_H

#include "../common.h"
#include "../Entity/EntityManager.h"
#include <functional>
#include <unordered_map>

template <typename T>
class Event {
    friend class EventManager;
    EVENTS name;
    int count = 0;
    std::unordered_map<int, std::function<void(EntityManager&, T)>> callbacks;
public:
    int addCallback(std::function<void(EntityManager&, T)>);
    void removeCallback(int);
    void trigger(T, EntityManager&);
};



#endif //TEARS_ENGINE_EVENT_H
