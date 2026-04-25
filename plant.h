#pragma once
#include "organism.h"

class Plant : public Organism {
public:
    Plant(int strength, int x, int y, World* world);

    void action() override;
    void collision(Organism* other) override;

    virtual Organism* spread(int newX, int newY) = 0;
};
