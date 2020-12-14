//
// Created by mahmoud on ٣‏/١١‏/٢٠٢٠.
//

#include "GameStateManager.h"
#include "GameState.h"



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

void GameStateManager::switchState(int key, MenuState* menuState, PlayState* playState) {
    if ( key == GLFW_KEY_ESCAPE){
        PlayState* play = dynamic_cast<PlayState*>(currentState);
        MenuState* menu = dynamic_cast<MenuState*>(currentState);
        if (play)
        {
            nextState = menu;
        }
        else if (menu)
        {
            nextState = play;
        }
    }
}