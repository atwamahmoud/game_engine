//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_SYSTEM_H
#define TEARS_ENGINE_SYSTEM_H


#include <string>
#include <vector>
#include <unordered_map>
#include "../Entity/EntityManager.h"
#include "../Events/EventManager.h"

using namespace std;

class System {
public:
    System();
    virtual void update(EntityManager&, EventManager&, double) = 0;
};


#endif //TEARS_ENGINE_SYSTEM_H
