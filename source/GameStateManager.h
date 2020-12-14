//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_GAMESTATEMANAGER_H
#define TEARS_ENGINE_GAMESTATEMANAGER_H

#include "./GameState.h"
#include <GLFW/glfw3.h>

class GameStateManager {
  GameState* currentState;
  GameState* nextState;
  bool shouldExit = false;
public:
  GameStateManager(GameState* crntState, GameState* nxtState);
  void goToState(GameState*&);
  void run(double delta1);
  void switchState(int key);
};


#endif //TEARS_ENGINE_GAMESTATEMANAGER_H
