#include "belladonna.h"
#include "world.h"

bool Belladonna::reactToAttack(Organism* attacker) {
    world->addLog("Belladonna kills " + attacker->getSpecies());
    attacker->setAlive(false);
    this->setAlive(false);
    return true;
}
