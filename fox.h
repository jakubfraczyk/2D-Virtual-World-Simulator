#pragma once
#include "animal.h"

class Fox : public Animal {
public:
    Fox(int x, int y, World* world)
        : Animal(3, 7, x, y, world) {}

    void action() override;
    char draw() const override { return 'F'; }
    std::string getSpecies() const override { return "Fox"; }
    Organism* createChild(int x, int y) override { return new Fox(x, y, world); }
};
