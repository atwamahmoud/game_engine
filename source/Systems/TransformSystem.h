//
// Created by ahmad on 07/12/2020.
//

#include <glm/glm.hpp>
#include "../Components/TransformComponent.h"
#include "../Mesh.hpp"
#include "../Entity/Entity.h"

#include<string>
#include <glm/gtx/euler_angles.hpp>

#ifndef TEARS_ENGINE_TRANSFORMSYSTEM_H
#define TEARS_ENGINE_TRANSFORMSYSTEM_H


class TransformSystem {
public:
    [[nodiscard]] glm::mat4 to_mat4(TransformComponent * comp) const;
    void update();
    void draw(glm::mat4 transformationMatrix,glm::mat4 cameraMatrix);

};


#endif //TEARS_ENGINE_TRANSFORMSYSTEM_H