#include "animal.h"
#include "world.h"
#include <cstdlib>

Animal::Animal(int strength, int initiative, int x, int y, World* world)
    : Organism(strength, initiative, x, y, world){}
void Animal::action(){
    int direction = rand() % 4;
    int newX = x, newY = y;
    switch (direction) {
        case 0: newY--; break;
        case 1: newY++; break;
        case 2: newX--; break;
        case 3: newX++; break;
    }
    if (world->isInBounds(newX, newY)){
        Organism* target = world->getOrganismAt(newX, newY);
        if(target == nullptr){
            x = newX;
            y = newY;
        }else if(target != this){
            collision(target);
        }
    }
}
void Animal::collision(Organism* other){
    if (this->getSpecies() == other->getSpecies()){
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(world->isCellFree(nx, ny)) {
                Organism* child = createChild(nx, ny);
                if (child != nullptr) {
                    world->addNewOrganism(child);
                    world->addLog(getSpecies() + " breeds");
                }
                break;
            }
        }
        return;
    }
    if (other->reactToAttack(this)){
        return;
    }
    if (this->strength >= other->getStrength()){
        world->addLog(this->getSpecies() + " kills " + other->getSpecies());
        other->setAlive(false);
        x = other->getX();
        y = other->getY();
    } else {
        world->addLog(other->getSpecies() + " kills " + this->getSpecies());
        this->setAlive(false);
    }
}
