#include "antelope.h"
#include "world.h"
#include <cstdlib>

void Antelope::action(){
    int direction = rand() % 4;
    int newX = x, newY = y;
    switch (direction) {
        case 0: newY -= 2; break;
        case 1: newY += 2; break;
        case 2: newX -= 2; break;
        case 3: newX += 2; break;
    }
    if(world->isInBounds(newX, newY)){
        Organism* target = world->getOrganismAt(newX, newY);
        if (target == nullptr) {
            x = newX;
            y = newY;
        } else if (target != this) {
            collision(target);
        }
    }
}
bool Antelope::reactToAttack(Organism* attacker){
    if(rand() % 2 == 0) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(world->isCellFree(nx, ny)) {
                x = nx;
                y = ny;
                world->addLog("Antelope escapes from " + attacker->getSpecies());
                return true;
            }
        }
    }
    return false;
}
