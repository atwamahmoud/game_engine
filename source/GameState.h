#ifndef TEARS_ENGINE_GAMESTATE_H
#define TEARS_ENGINE_GAMESTATE_H
//#include <glm/glm.hpp>
//#include <GLFW/glfw3.h>

class GameState {

public:
  virtual void onEnter() = 0;
  virtual void onDraw(double delta1) = 0;
  virtual void onExit() = 0;
  virtual GameState* handleEvents() = 0;
};


#endif
