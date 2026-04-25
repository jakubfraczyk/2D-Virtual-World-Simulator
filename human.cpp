#include "human.h"
#include "world.h"
#include <cstdlib>
#include <sstream>

Human::Human(int x, int y, World* world)
    : Animal(5, 4, x, y, world), direction(-1), abilityDuration(0), abilityCooldown(0) {}
void Human::setDirection(int dir) {
    direction = dir;
}
void Human::activateAbility() {
    if (abilityCooldown == 0 && abilityDuration == 0){
        abilityDuration = 5;
        world->addLog("Human activates Immortality!");
    }
}
bool Human::isAbilityActive() const{
    return abilityDuration > 0;
}
int Human::getAbilityCooldown() const{
    return abilityCooldown;
}
int Human::getAbilityDuration() const{
    return abilityDuration;
}
void Human::action(){
    if(abilityDuration > 0) {
        abilityDuration--;
        if(abilityDuration == 0){
            abilityCooldown = 5;
            world->addLog("Human Immortality wears off");
        }
    } else if(abilityCooldown > 0) {
        abilityCooldown--;
    }
    if(direction == -1) return;
    int newX = x, newY = y;
    switch (direction) {
        case 0: newY--; break;
        case 1: newY++; break;
        case 2: newX--; break;
        case 3: newX++; break;
    }
    direction = -1;
    if (world->isInBounds(newX, newY)) {
        Organism* target = world->getOrganismAt(newX, newY);
        if(target == nullptr) {
            x = newX;
            y = newY;
        } else {
            collision(target);
        }
    }
}
void Human::collision(Organism* other){
    if (this->getSpecies() == other->getSpecies()) {
        return;
    }
    if(other->reactToAttack(this)){
        if (!this->isAlive() && abilityDuration > 0) {
            this->setAlive(true);
            int dx[] = {0, 0, -1, 1};
            int dy[] = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (world->isCellFree(nx, ny)) {
                    x = nx;
                    y = ny;
                    break;
                }
            }
            world->addLog("Human survives using Immortality");
        }
        return;
    }
    if (this->strength >= other->getStrength()) {
        world->addLog(this->getSpecies() + " kills " + other->getSpecies());
        other->setAlive(false);
        x = other->getX();
        y = other->getY();
    } else{
        if(abilityDuration > 0) {
            int dx[] = {0, 0, -1, 1};
            int dy[] = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(world->isCellFree(nx, ny)) {
                    x = nx;
                    y = ny;
                    break;
                }
            }
            world->addLog("Human survives using Immortality");
        } else {
            world->addLog(other->getSpecies() + " kills " + this->getSpecies());
            this->setAlive(false);
        }
    }
}
bool Human::reactToAttack(Organism* attacker) {
    if (abilityDuration > 0) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (world->isCellFree(nx, ny)) {
                x = nx;
                y = ny;
                world->addLog("Human escapes using Immortality");
                return true;
            }
        }
        return true;
    }
    return false;
}
std::string Human::serialize() const {
    std::ostringstream oss;
    oss << Organism::serialize() << " " << direction
        << " " << abilityDuration << " " << abilityCooldown;
    return oss.str();
}

void Human::setAbilityDuration(int d) { abilityDuration = d; }
void Human::setAbilityCooldown(int c) { abilityCooldown = c; }
int Human::getDirection() const { return direction; }
