#pragma once
#include <string>
#include <sstream>

class World;

class Organism{
protected:
    int strength;
    int initiative;
    int x;
    int y;
    int age;
    bool alive;
    World* world;
public:
    Organism(int strength, int initiative, int x, int y, World* world)
        : strength(strength), initiative(initiative), x(x), y(y),
          age(0), alive(true), world(world) {}

    virtual ~Organism() = default;
    virtual void action() = 0;
    virtual void collision(Organism* other) = 0;
    virtual char draw() const = 0;
    virtual std::string getSpecies() const = 0;
    virtual bool reactToAttack(Organism* attacker){ return false; }
    virtual std::string serialize() const {
        std::ostringstream oss;
        oss<< getSpecies() << " " << strength << " " << initiative
            << " " << x << " " << y << " " << age;
        return oss.str();
    }
    int getStrength() const { return strength; }
    int getInitiative() const { return initiative; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getAge() const { return age; }
    bool isAlive() const { return alive; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void setStrength(int s) { strength = s; }
    void setAlive(bool a) { alive = a; }
    void increaseAge() { age++; }
    void setAge(int a) { age = a; }
};
