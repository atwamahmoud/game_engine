//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_TRANSFORM_COMPONENT_H
#define TEARS_ENGINE_TRANSFORM_COMPONENT_H


#include "Component.h"
#include <vector>
//glm vec:3
struct Coordinate {
  float x;
  float y;
  float z;
};

//GetEntitiesHaving 

class TransformComponent: public Component {
public:
    TransformComponent(Coordinate,Coordinate,Coordinate, int);
    Coordinate position;
    Coordinate rotation;
    Coordinate scale;
    // Using GetEntitiesHaving in the EntityManager Class, we don't need the Parent ID.
    // The parent ID however will be needed in case of the first approach but who got the time for that.
    // If you really want it here it is...
    int entityId;



};


#endif //TEARS_ENGINE_TRANSFORM_COMPONENT_H
