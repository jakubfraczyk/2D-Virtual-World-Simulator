#include "guarana.h"
#include "world.h"

bool Guarana::reactToAttack(Organism* attacker) {
    attacker->setStrength(attacker->getStrength() + 3);
    world->addLog(attacker->getSpecies() + " eats Guarana (+3 strength)");
    return false;
}
