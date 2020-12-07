#include "RenderSystem.h"
#include "../Components/CameraComponent.hpp"
#include "../Components/MeshRenderer.h"
#include "../Components/TransformComponent.h"
#include "../Components/Material.h"
#include <vector>
#include "../Program.h"


TransformComponent *transformComp;
MeshRenderer *renderer;
CameraComponent *cameraComponent;
Material *material;

string transformComponentName = typeid(transformComp).name();
string meshRendererName = typeid(renderer).name();
string cameraComponentName = typeid(cameraComponent).name();
string materialComponentName = typeid(material).name();

void RenderSystem::update(EntityManager &entityManager,
                          EventManager &eventManager, double dt) {
  std::vector<Entity *> entities = entityManager.getEntitiesHaving({
      meshRendererName,
      transformComponentName,
  });

  // Get Camera Entity....
  if (camera == nullptr) {
    std::vector<Entity *> entities = entityManager.getEntitiesHaving({
        cameraComponentName,
        transformComponentName,
    });
    if (entities.size() == 0) {
      throw "Couldn't find the camera entity...";
      return;
    }
    if (entities.size() > 1) {
      std::cout << "Multiple cameras found, selecting the first one...";
    }
    camera = entities[0];
  }
  for (Entity *entity : entities) {
    // transform...
    // renderer...
      transformComp = dynamic_cast<TransformComponent *>(
        entity->components[transformComponentName]);
    renderer =
        dynamic_cast<MeshRenderer *>(entity->components[meshRendererName]);
    
    renderer->mesh->draw();
  }
    transformComp = nullptr;
  renderer = nullptr;

  entities = entityManager.getEntitiesHaving({materialComponentName});

  // Get Camera Entity....
  for (Entity *entity : entities) {
    // transform...
    // renderer...
    Material* material = dynamic_cast<Material *>(entity->components[materialComponentName]);

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(*material->shader);

    for (std::pair<string, std::vector<float>> element : material->uniformMap) {
      GLint loc = glGetUniformLocation(*material->shader, element.first.c_str());
      switch(element.second.size()){
        case 1:
          glUniform1f(loc, element.second[0]);
          break;
        case 2:
          glUniform2f(loc, element.second[0], element.second[1]);
          break;
        case 3:
          glUniform3f(loc, element.second[0], element.second[1], element.second[2]);
          break;
        case 4:
          glUniform4f(loc, element.second[0],element.second[1],element.second[2], element.second[3]);
          break;
        default:
          break;
      } 
    }

  }
    transformComp = nullptr;
  renderer = nullptr;
}
