//
// Created by mahmoud on ٦‏/١١‏/٢٠٢٠.
//

#include "Event.h"


template<typename T>
int Event<T>::addCallback(std::function<void(EntityManager&, T)> func) {
    this->callbacks[count] = func;
    return count++;
}

template<typename T>
void Event<T>::trigger(T data, EntityManager & manager) {
    for(std::pair<int, std::function<void(EntityManager&, T)>> element: this->callbacks) {
        element.second(data, manager);
    }
}

template<typename T>
void Event<T>::removeCallback(int id) {
    this->callbacks.erase(id);
}

