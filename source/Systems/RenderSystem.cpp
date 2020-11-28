#include "RenderSystem.h"
#include "../Components/CameraComponent.h"
#include "../Components/MeshRenderer.h"
#include "../Components/TransformComponent.h"
#include <vector>

TransformComponent *transform;
MeshRenderer *renderer;
CameraComponent *cameraComponent;

string transformComponentName = typeid(transform).name();
string meshRendererName = typeid(renderer).name();
string cameraComponentName = typeid(cameraComponent).name();

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
    transform = dynamic_cast<TransformComponent *>(
        entity->components[transformComponentName]);
    renderer =
        dynamic_cast<MeshRenderer *>(entity->components[meshRendererName]);

    renderer->mesh->draw(transform,
                         dynamic_cast<TransformComponent *>(
                             camera->components[transformComponentName]),
                         dynamic_cast<CameraComponent *>(
                             camera->components[cameraComponentName]));
  }
  transform = nullptr;
  renderer = nullptr;
}
