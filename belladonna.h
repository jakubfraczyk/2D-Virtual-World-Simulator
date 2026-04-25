#pragma once
#include "plant.h"

class Belladonna : public Plant{
public:
    Belladonna(int x, int y, World* world) : Plant(99, x, y, world){}
    bool reactToAttack(Organism* attacker) override;
    char draw() const override{ return 'b';}
    std::string getSpecies() const override { return "Belladonna";}
    Organism* spread(int newX, int newY) override{
        return new Belladonna(newX, newY, world);
    }
};
