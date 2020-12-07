//
// Created by atwa on 11/7/20.
//

#include "MovementSystem.h"
#include "../Components/Position.h"

Position *xpos;

string MovementName = typeid(xpos).name();

void MovementSystem::update(EntityManager &, EventManager &eventManager,
                            double dt) {

  if (didSubscribe)
    return;

  didSubscribe = true;

  eventManager.mouseEvent.addCallback([](EntityManager &entityManager,
                                         MousePosition position) {
    vector<Entity *> entities = entityManager.getEntitiesHaving({MovementName});

    std::cout << "X: " << position.x << ", Y: " << position.y << "\n";

    for (int i = 0; i < entities.size(); i++) {
      Position *pos = dynamic_cast<Position *>(entities[i]->components[MovementName]);
      pos->x = position.x;
      pos->y = position.y;
    }
  });
}
