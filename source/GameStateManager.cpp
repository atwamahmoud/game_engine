//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#include "GameStateManager.h"
#include "GameState.h"


void GameStateManager::run() {
  while (!shouldExit) {
    if(nextState != nullptr) {
      
      if(currentState != nullptr)
        currentState->onExit();

      currentState = nextState;
      
      nextState = nullptr;
      
      currentState->onEnter();
    }
    if(currentState != nullptr) {
      currentState->onDraw();
    }
  }
  if(currentState != nullptr) {
    currentState->onExit();
  }
}

void GameStateManager::goToState(GameState*& state) {
  nextState = state;
}