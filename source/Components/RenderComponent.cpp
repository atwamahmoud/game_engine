//
// Created by atwa on 11/7/20.
//

#include "RenderComponent.h"

RenderComponent::RenderComponent(string vertexShader, string fragShader, bool shouldRender, string ID) {
    this->ID = ID;
    this->fragmentShaderLocation = fragShader;
    this->vertexShaderLocation = vertexShader;
    this->shouldBeRendered = shouldRender;
}
