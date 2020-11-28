#ifndef TEARS_ENGINE_GAMESTATE_H
#define TEARS_ENGINE_GAMESTATE_H


class GameState {

public:
  virtual void onEnter() = 0;
  virtual void onDraw() = 0;
  virtual void onExit() = 0;
};


#endif
