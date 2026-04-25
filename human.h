#pragma once
#include "animal.h"

class Human : public Animal{
private:
    int direction;
    int abilityDuration;
    int abilityCooldown;

public:
    Human(int x, int y, World* world);
    void action() override;
    void collision(Organism* other) override;
    bool reactToAttack(Organism* attacker) override;
    char draw() const override { return 'H'; }
    std::string getSpecies() const override { return "Human";}
    void setDirection(int dir);
    void activateAbility();
    bool isAbilityActive() const;
    int getAbilityCooldown() const;
    int getAbilityDuration() const;
    int getDirection() const;
    std::string serialize() const override;
    void setAbilityDuration(int d);
    void setAbilityCooldown(int c);
};
