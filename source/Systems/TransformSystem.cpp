//
// Created by ahmad on 07/12/2020.
//

#include "TransformSystem.h"

[[nodiscard]] glm::mat4 TransformSystem::to_mat4(TransformComponent * comp) const {
    const glm::vec3& translation = {comp->position.x,comp->position.y,comp->position.z};
    const glm::vec3& scale = {comp->scale.x,comp->scale.y,comp->scale.z};
    return glm::translate(glm::mat4(1.0f), translation)
           * glm::yawPitchRoll(comp->rotation.y, comp->rotation.x, comp->rotation.z)
           * glm::scale(glm::mat4(1.0f), scale);
}
void TransformSystem::update(){}
void TransformSystem::draw(glm::mat4 transformationMatrix,glm::mat4 cameraMatrix){}



