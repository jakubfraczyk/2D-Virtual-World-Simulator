#pragma once
#include "animal.h"

class Turtle : public Animal{
public:
    Turtle(int x, int y, World* world)
        : Animal(2, 1, x, y, world) {}
    void action() override;
    bool reactToAttack(Organism* attacker) override;
    char draw() const override { return 'T'; }
    std::string getSpecies() const override { return "Turtle"; }
    Organism* createChild(int x, int y) override { return new Turtle(x, y, world); }
};
