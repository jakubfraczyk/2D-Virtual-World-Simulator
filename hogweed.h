#pragma once
#include "plant.h"

class SosnowskysHogweed : public Plant{
public:
    SosnowskysHogweed(int x, int y, World* world) : Plant(10, x, y, world) {}

    void action() override;
    bool reactToAttack(Organism* attacker) override;
    char draw() const override { return 'h'; }
    std::string getSpecies() const override { return "Hogweed";}
    Organism* spread(int newX, int newY) override {
        return new SosnowskysHogweed(newX, newY, world);
    }
};
