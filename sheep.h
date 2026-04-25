#pragma once
#include "animal.h"

class Sheep : public Animal {
public:
    Sheep(int x, int y, World* world)
        : Animal(4, 4, x, y, world) {}

    char draw() const override { return 'S'; }
    std::string getSpecies() const override { return "Sheep"; }
    Organism* createChild(int x, int y) override { return new Sheep(x, y, world); }
};
