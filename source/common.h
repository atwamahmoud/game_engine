//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//
#include <chrono>

#ifndef TEARS_ENGINE_COMMON_H
#define TEARS_ENGINE_COMMON_H

using namespace std;
using namespace std::chrono;

inline double getTime() {
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

enum EVENTS {
    MOUSE_MOVE,
};


#endif //TEARS_ENGINE_COMMON_H
