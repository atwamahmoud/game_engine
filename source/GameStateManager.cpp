//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#include "GameStateManager.h"
#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"


GameStateManager::GameStateManager(GameState* crntState, GameState* nxtState){
    this->currentState = crntState;
    this->nextState = nxtState;
}

void GameStateManager::run(double delta1) {

    if(nextState != nullptr) {
      
      if(currentState != nullptr)
        currentState->onExit();

      currentState = nextState;
      
      nextState = nullptr;
      
      currentState->onEnter();
    }
    if(currentState != nullptr) {
      currentState->onDraw(delta1);
    }

//  if(currentState != nullptr) {
//    currentState->onExit();
//  }
}

void GameStateManager::goToState(GameState*& state) {
  nextState = state;
}

void GameStateManager::switchState(int key) {
    if ( key == GLFW_KEY_ESCAPE){
        PlayState* play = dynamic_cast<PlayState*>(currentState);
        MenuState* menu = dynamic_cast<MenuState*>(currentState);
        if (play)
        {

        }
        else if (menu)
        {

        }
        GameState* ptr = currentState;
        currentState = nextState;
        nextState = ptr;
    }
}