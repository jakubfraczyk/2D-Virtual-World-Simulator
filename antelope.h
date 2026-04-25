#pragma once
#include "animal.h"

class Antelope : public Animal{
public:
    Antelope(int x, int y, World* world)
        : Animal(4, 4, x, y, world) {}

    void action() override;
    bool reactToAttack(Organism* attacker) override;
    char draw() const override { return 'A';}
    std::string getSpecies() const override { return "Antelope"; }
    Organism* createChild(int x, int y) override { return new Antelope(x, y, world); }
};
