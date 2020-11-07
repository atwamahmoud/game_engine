//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_RENDERCOMPONENT_H
#define TEARS_ENGINE_RENDERCOMPONENT_H

#include "../common.h"
#include "Component.h"
#include <unordered_map>

class RenderComponent: public Component {
public:
    RenderComponent(string, string, bool, string);
    string vertexShaderLocation = "";
    string fragmentShaderLocation = "";
    bool shouldBeRendered = false;
    string ID = "";
};


#endif //TEARS_ENGINE_RENDERCOMPONENT_H
