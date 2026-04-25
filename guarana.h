#pragma once
#include "plant.h"

class Guarana : public Plant{
public:
    Guarana(int x, int y, World* world) : Plant(0, x, y, world) {}

    bool reactToAttack(Organism* attacker) override;
    char draw() const override { return 'u';}
    std::string getSpecies() const override { return "Guarana";}
    Organism* spread(int newX, int newY) override {
        return new Guarana(newX, newY, world);
    }
};
