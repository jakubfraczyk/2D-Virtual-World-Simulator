#include "hogweed.h"
#include "world.h"

void SosnowskysHogweed::action(){
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i< 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (world->isInBounds(nx, ny)){
            Organism* neighbor = world->getOrganismAt(nx, ny);
            if (neighbor != nullptr && neighbor->getInitiative() > 0){
                world->addLog("Sosnowsky's Hogweed kills " + neighbor->getSpecies());
                neighbor->setAlive(false);
            }
        }
    }
    Plant::action();
}
bool SosnowskysHogweed::reactToAttack(Organism* attacker){
    world->addLog("Sosnowsky's Hogweed kills " + attacker->getSpecies());
    attacker->setAlive(false);
    this->setAlive(false);
    return true;
}
