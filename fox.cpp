#include "fox.h"
#include "world.h"
#include <cstdlib>

void Fox::action() {
    int direction = rand() % 4;
    int newX = x, newY = y;
    switch(direction){
        case 0: newY--; break;
        case 1: newY++; break;
        case 2: newX--; break;
        case 3: newX++; break;
    }
    if(world->isInBounds(newX, newY)){
        Organism* target = world->getOrganismAt(newX, newY);
        if (target == nullptr) {
            x = newX;
            y = newY;
        } else if (target->getStrength() > this->strength){
            return;
        } else {
            collision(target);
        }
    }
}
