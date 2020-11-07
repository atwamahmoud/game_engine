//
// Created by atwa on 11/7/20.
//

#include "MovementSystem.h"
#include "../Components/Position.h"

Position* xpos;

string name = typeid(xpos).name();


void MovementSystem::update(EntityManager &, EventManager & eventManager, double dt) {

    if(didSubscribe) return;

    didSubscribe = true;


    eventManager.mouseEvent.addCallback([](EntityManager& entityManager, MousePosition position) {
        vector<Entity*> entities = entityManager.getEntitiesHaving({name});

        std::cout<<"X: "<<position.x<<", Y: "<<position.y<<"\n";

        for(int i = 0; i < entities.size(); i++) {
            Position* pos = dynamic_cast<Position*>(entities[i]->components[name]);
            pos->x = position.x;
            pos->y = position.y;
        }
    });

}
