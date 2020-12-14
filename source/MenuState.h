//
// Created by ahmad on 14/12/2020.
//

#ifndef TEARS_ENGINE_MENUSTATE_H
#define TEARS_ENGINE_MENUSTATE_H

#include "GameState.h"
#include "Program.h"

class MenuState : public GameState {
private:
    Program prog;
public:

    void onEnter();
    void onDraw(double delta1);
    void onExit();
    GameState* handleEvents();
};


#endif //TEARS_ENGINE_MENUSTATE_H
