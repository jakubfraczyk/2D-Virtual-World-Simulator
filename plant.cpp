#include "plant.h"
#include "world.h"
#include <cstdlib>

Plant::Plant(int strength, int x, int y, World* world)
    : Organism(strength, 0, x, y, world) {}

void Plant::action(){
    if (rand() % 100 <3){
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int start = rand() % 8;
        for (int i = 0; i < 8; i++) {
            int idx = (start + i) % 8;
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (world->isCellFree(nx, ny)) {
                world->addNewOrganism(spread(nx, ny));
                return;
            }
        }
    }
}
void Plant::collision(Organism* other) {}
