//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_GAMESTATEMANAGER_H
#define TEARS_ENGINE_GAMESTATEMANAGER_H

#include "./GameState.h"

class GameStateManager {
  GameState* currentState;
  GameState* nextState;
  bool shouldExit = false;
  
  void goToState(GameState*&);
  void run();
};


#endif //TEARS_ENGINE_GAMESTATEMANAGER_H
