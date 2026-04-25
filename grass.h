#pragma once
#include "plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y, World* world) : Plant(0, x, y, world) {}

    char draw() const override { return 'g'; }
    std::string getSpecies() const override { return "Grass"; }
    Organism* spread(int newX, int newY) override {
        return new Grass(newX, newY, world);
    }
};
