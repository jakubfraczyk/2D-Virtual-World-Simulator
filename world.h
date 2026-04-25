#pragma once
#include <vector>
#include <string>
#include "organism.h"

class Human;

class World {
private:
    int width;
    int height;
    int turn;
    std::vector<Organism*> organisms;
    std::vector<Organism*> newOrganisms;
    std::string logs;
public:
    World(int w, int h);
    ~World();
    void makeTurn();
    void drawWorld() const;
    void addOrganism(Organism* org);
    void addNewOrganism(Organism* org);
    void addLog(const std::string& message);
    Organism* getOrganismAt(int x, int y) const;
    bool isInBounds(int x, int y) const;
    bool isCellFree(int x, int y) const;
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    Human* findHuman() const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getTurn() const { return turn; }
};
