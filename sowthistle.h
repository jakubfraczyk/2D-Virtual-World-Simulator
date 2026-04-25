#pragma once
#include "plant.h"

class SowThistle : public Plant{
public:
    SowThistle(int x, int y, World* world) : Plant(0, x, y, world) {}
    void action() override;
    char draw() const override { return 't'; }
    std::string getSpecies() const override { return "SowThistle"; }
    Organism* spread(int newX, int newY) override {
        return new SowThistle(newX, newY, world);
    }
};
