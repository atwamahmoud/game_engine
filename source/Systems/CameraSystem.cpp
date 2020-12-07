//
// Created by atwa on 11/7/20.
//

#include "CameraSystem.hpp"
#include "../Components/CameraComponent.hpp"

CameraComponent *camera;

string name = typeid(camera).name();
float prevX = 0; 
float prevY = 0;
float deltaX = 0;
float deltaY = 0;
void CameraSystem::update(EntityManager &, EventManager &eventManager,
                            double dt) {

  if (didSubscribe)
    return;

  didSubscribe = true;

  eventManager.keyboardEvent.addCallback([this](EntityManager &entityManager,
                                         int key) {
    vector<Entity *> entities = entityManager.getEntitiesHaving({name});

    for (int i = 0; i < entities.size(); i++) {
      CameraComponent *camera = dynamic_cast<CameraComponent *>(entities[i]->components[name]);

      if(this->pitch < -glm::half_pi<float>() * 0.99f) this->pitch = -glm::half_pi<float>() * 0.99f;
      if(this->pitch >  glm::half_pi<float>() * 0.99f) this->pitch  = glm::half_pi<float>() * 0.99f;
      this->yaw = glm::wrapAngle(yaw);
      glm::vec3 front = camera->Forward(), up = camera->Up(), right = camera->Right();

      glm::vec3 current_sensitivity = this->position_sensitivity;
      if(key ==GLFW_KEY_LEFT_SHIFT) current_sensitivity *= speedup_factor;
      
      int delta_time = 1;
      if(key == GLFW_KEY_W) position += front * ((float)delta_time * current_sensitivity.z);
      if(key ==GLFW_KEY_S) position -= front * ((float)delta_time * current_sensitivity.z);
      if(key ==GLFW_KEY_Q) position += up * ((float)delta_time * current_sensitivity.y);
      if(key ==GLFW_KEY_E) position -= up * ((float)delta_time * current_sensitivity.y);
      if(key ==GLFW_KEY_D) position += right * ((float)delta_time * current_sensitivity.x);
      if(key ==GLFW_KEY_A) position -= right * ((float)delta_time * current_sensitivity.x);

      camera->setDirection(glm::vec3(glm::cos(yaw), 0, -glm::sin(yaw)) * glm::cos(pitch) + glm::vec3(0, glm::sin(pitch), 0));
      camera->setEyePosition(position);
    }
  });

  eventManager.mouseEvent.addCallback([this](EntityManager &entityManager,
                                         MousePosition pos) {
    vector<Entity *> entities = entityManager.getEntitiesHaving({name});

    for (int i = 0; i < entities.size(); i++) {
      deltaX = pos.x - prevX;
      deltaY = pos.y - prevY;
      prevX = pos.x;
      prevY = pos.y;
      CameraComponent *camera = dynamic_cast<CameraComponent *>(entities[i]->components[name]);

      float fov = camera->getVerticalFieldOfView() + pos.y * fov_sensitivity;
      fov = glm::clamp(fov, glm::pi<float>() * 0.01f, glm::pi<float>() * 0.99f);
      camera->setVerticalFieldOfView(fov);

    }
  });

  eventManager.mouseClickEvent.addCallback([this](EntityManager &entityManager,
                                         int key){
      // if(key == GLFW_MOUSE_BUTTON_1 && !mouse_locked){
        // app->getMouse().lockMouse(app->getWindow());
        // mouse_locked = true;
      // } else if(!app->getMouse().isPressed(GLFW_MOUSE_BUTTON_1) && mouse_locked) {
        // app->getMouse().unlockMouse(app->getWindow());
        // mouse_locked = false;
      // }

      if(key == GLFW_MOUSE_BUTTON_1){
        pitch -= deltaY * pitch_sensitivity;
        yaw -= deltaX * yaw_sensitivity;
      }
  });

}
