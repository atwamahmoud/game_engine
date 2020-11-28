//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//
#include "../vendor/glad/include/glad/gl.h"
#include "../vendor/glfw/include/GLFW/glfw3.h"
#include <chrono>
#include <fstream>
#include <iostream>

#ifndef TEARS_ENGINE_COMMON_H
#define TEARS_ENGINE_COMMON_H

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;
using namespace std::chrono;

inline double getTime() {
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}

enum EVENTS { MOUSE_MOVE, KEYBOARD };

#endif // TEARS_ENGINE_COMMON_H
