#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "world.h"
#include "wolf.h"
#include "sheep.h"
#include "fox.h"
#include "turtle.h"
#include "antelope.h"
#include "grass.h"
#include "sowthistle.h"
#include "guarana.h"
#include "belladonna.h"
#include "hogweed.h"
#include "human.h"

#define BOARD_W 20
#define BOARD_H 20
#define SAVE_FILE "save.txt"
int main(){
    srand(time(0));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    World world(BOARD_W, BOARD_H);
    Human* human = new Human(10, 5, &world);
    world.addOrganism(human);
    world.addOrganism(new Wolf(3, 3, &world));
    world.addOrganism(new Wolf(15, 12, &world));
    world.addOrganism(new Sheep(5, 5, &world));
    world.addOrganism(new Sheep(7, 3, &world));
    world.addOrganism(new Sheep(12, 8, &world));
    world.addOrganism(new Fox(1, 1, &world));
    world.addOrganism(new Fox(18, 18, &world));
    world.addOrganism(new Turtle(10, 10, &world));
    world.addOrganism(new Turtle(6, 14, &world));
    world.addOrganism(new Antelope(8, 2, &world));
    world.addOrganism(new Antelope(14, 16, &world));
    world.addOrganism(new Grass(0, 0, &world));
    world.addOrganism(new Grass(19, 19, &world));
    world.addOrganism(new SowThistle(4, 12, &world));
    world.addOrganism(new Guarana(9, 7, &world));
    world.addOrganism(new Belladonna(16, 5, &world));
    world.addOrganism(new SosnowskysHogweed(11, 11, &world));
    bool gameRunning = true;
    while(gameRunning) {
        clear();
        world.drawWorld();
        human = world.findHuman();
        if(human == nullptr) {
            printw("\n GAME OVER\n");
            printw("You survived %d turns\n", world.getTurn());
            printw("\nPress any key to exit\n");
            refresh();
            getch();
            break;
        }
        if(human->isAbilityActive()){
            printw("Immortality ACTIVE: %d turns\n", human->getAbilityDuration());
        } else if(human->getAbilityCooldown() > 0) {
            printw("Immortality cooldown: %d\n", human->getAbilityCooldown());
        }
        printw("\nArrows=move  p=ability  s=save  l=load  q=quit\n");
        refresh();
        int ch = getch();
        if (ch == 'q')break;
        if(ch == 's') {
            world.saveToFile(SAVE_FILE);
            continue;
        }
        if(ch == 'l') {
            world.loadFromFile(SAVE_FILE);
            human = world.findHuman();
            continue;
        }
        if (ch == 'p') {
            human->activateAbility();
        }
        switch (ch) {
            case KEY_UP:    human->setDirection(0); break;
            case KEY_DOWN:  human->setDirection(1); break;
            case KEY_LEFT:  human->setDirection(2); break;
            case KEY_RIGHT: human->setDirection(3); break;
        }
        world.makeTurn();
    }
    endwin();
    return 0;
}
