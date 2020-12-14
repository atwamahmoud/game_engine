//
// Created by ahmad on 14/12/2020.
//

#include "MenuState.h"


void MenuState::onEnter() {
    prog = Program();
}

void MenuState::onDraw(double delta1) {

    prog.draw(234);
}

void MenuState::onExit() {

}


