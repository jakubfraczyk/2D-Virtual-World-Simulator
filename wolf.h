#pragma once
#include "animal.h"

class Wolf : public Animal {
public:
    Wolf(int x, int y, World* world)
        : Animal(9, 5, x, y, world) {}

    char draw() const override { return 'W'; }
    std::string getSpecies() const override { return "Wolf"; }
    Organism* createChild(int x, int y) override { return new Wolf(x, y, world); }
};
