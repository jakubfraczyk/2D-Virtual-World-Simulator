#pragma once
#include "organism.h"

class Animal : public Organism {
public:
    Animal(int strength, int initiative, int x, int y, World* world);

    void action() override;
    void collision(Organism* other) override;

    virtual Organism* createChild(int x, int y) { return nullptr; }
};
