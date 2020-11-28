
#include "TransformComponent.h"

TransformComponent::TransformComponent(Coordinate position, Coordinate rotation, Coordinate scale, int entityId)  {
  this->rotation = rotation;
  this->scale = scale;
  this->position = position;
  this->entityId = entityId;
};