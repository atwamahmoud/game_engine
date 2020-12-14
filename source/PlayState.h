//
// Created by ahmad on 14/12/2020.
//

#ifndef TEARS_ENGINE_PLAYSTATE_H
#define TEARS_ENGINE_PLAYSTATE_H

#include "GameState.h"
class PlayState: public GameState {
    void onEnter();
    void onDraw(double delta1);
    void onExit();
    GameState* handleEvents();
};


#endif //TEARS_ENGINE_PLAYSTATE_H
