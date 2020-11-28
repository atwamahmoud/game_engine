
#ifndef TEARS_ENGINE_RENDERSYSTEM_H
#define TEARS_ENGINE_RENDERSYSTEM_H

#include "../Components/TransformComponent.h"
#include "System.h"

class RenderSystem : public System {
private:
  Entity *camera = nullptr;

public:
  void update(EntityManager &, EventManager &, double) override;
};

#endif // TEARS_ENGINE_RENDERSYSTEM_H
