#include "turtle.h"
#include "world.h"
#include <cstdlib>

void Turtle::action() {
    if (rand() % 100 < 75) return;
    Animal::action();
}

bool Turtle::reactToAttack(Organism* attacker) {
    if (attacker->getStrength() < 5) {
        world->addLog("Turtle deflects " + attacker->getSpecies());
        return true;
    }
    return false;
}
