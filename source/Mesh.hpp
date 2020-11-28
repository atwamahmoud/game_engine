//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_MESH
#define TEARS_ENGINE_MESH
#include "./Components/CameraComponent.h"
#include "./Components/TransformComponent.h"
class Mesh {
private:
public:
  void draw(TransformComponent *, TransformComponent *, CameraComponent *);
};

#endif // TEARS_ENGINE_MESH
