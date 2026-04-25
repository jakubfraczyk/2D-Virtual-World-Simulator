#include "world.h"
#include <ncurses.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "wolf.h"
#include "sheep.h"
#include "fox.h"
#include "turtle.h"
#include "antelope.h"
#include "human.h"
#include "grass.h"
#include "sowthistle.h"
#include "guarana.h"
#include "belladonna.h"
#include "hogweed.h"

World::World(int w, int h) : width(w), height(h), turn(0){}
World::~World(){
    for (Organism* org : organisms){
        delete org;
    }
}
Organism* World::getOrganismAt(int x, int y) const{
    for(Organism* org : organisms){
        if(org->isAlive() && org->getX() == x && org->getY() == y){
            return org;
        }
    }
    return nullptr;
}
bool World::isInBounds(int x, int y) const{
    return x >= 0 && x < width && y >= 0 && y < height;
}
bool World::isCellFree(int x, int y) const{
    return isInBounds(x, y) && getOrganismAt(x, y) == nullptr;
}
void World::addOrganism(Organism* org){
    organisms.push_back(org);
}
void World::addNewOrganism(Organism* org){
    newOrganisms.push_back(org);
}
void World::addLog(const std::string& message){
    logs += message + "\n";
}
void World::makeTurn(){
    logs = "";
    turn++;
    std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b){
        if (a->getInitiative() == b->getInitiative())
            return a->getAge() > b->getAge();
        return a->getInitiative() > b->getInitiative();
    });
    for(Organism* org : organisms){
        if (org->isAlive()){
            org->action();
        }
    }
    for (Organism* org : organisms){
        if (org->isAlive()){
            org->increaseAge();
        }
    }
    for (int i = organisms.size() - 1; i >= 0; i--){
        if (!organisms[i]->isAlive()){
            delete organisms[i];
            organisms.erase(organisms.begin() + i);
        }
    }
    for (Organism* org : newOrganisms){
        organisms.push_back(org);
    }
    newOrganisms.clear();
}
void World::drawWorld() const{
    printw("Turn: %d\n", turn);
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            Organism* org = getOrganismAt(x, y);
            if(org != nullptr)
                printw("%c ", org->draw());
            else
                printw(". ");
        }
        printw("\n");
    }
    if (!logs.empty()) {
        printw("\n   Events    \n%s", logs.c_str());
    }
}
Human* World::findHuman() const{
    for(Organism* org : organisms){
        if (org->getSpecies() == "Human" && org->isAlive()){
            return dynamic_cast<Human*>(org);
        }
    }
    return nullptr;
}
void World::saveToFile(const std::string& filename){
    std::ofstream file(filename);
    if(!file.is_open()) {
        addLog("Cannot save to file");
        return;
    }
    file << width << " " << height << " " << turn << "\n";
    for (Organism* org : organisms) {
        if (org->isAlive()) {
            file << org->serialize() << "\n";
        }
    }
    file.close();
    addLog("Game saved to " + filename);
}
void World::loadFromFile(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        addLog("Cannot open file: " + filename);
        return;
    }
    for(Organism* org : organisms){
        delete org;
    }
    organisms.clear();
    newOrganisms.clear();
    file >> width >> height >> turn;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        if(line.empty()) continue;
        std::istringstream iss(line);
        std::string type;
        int str, init, ox, oy, oage;
        iss>>type>>str>>init>>ox>>oy>>oage;
        Organism* org = nullptr;
        if (type == "Wolf") org = new Wolf(ox, oy, this);
        else if (type == "Sheep") org = new Sheep(ox, oy, this);
        else if (type == "Fox") org = new Fox(ox, oy, this);
        else if (type == "Turtle") org = new Turtle(ox, oy, this);
        else if (type == "Antelope") org = new Antelope(ox, oy, this);
        else if (type == "Human") {
            int dir, dur, cd;
            iss >>dir>>dur>> cd;
            Human* h = new Human(ox, oy, this);
            h->setDirection(dir);
            h->setAbilityDuration(dur);
            h->setAbilityCooldown(cd);
            org = h;
        }
        else if (type == "Grass") org = new Grass(ox, oy, this);
        else if (type == "SowThistle") org = new SowThistle(ox, oy, this);
        else if (type == "Guarana") org = new Guarana(ox, oy, this);
        else if (type == "Belladonna") org = new Belladonna(ox, oy, this);
        else if (type == "SosnowskysHogweed") org = new SosnowskysHogweed(ox, oy, this);
        if (org != nullptr) {
            org->setStrength(str);
            org->setAge(oage);
            organisms.push_back(org);
        }
    }
    file.close();
    addLog("Game loaded from " + filename);
}
