# 2D-Virtual-World-Simulator
# 2D Virtual World Simulator

## Overview
A turn-based 2D virtual world simulator created as an academic project for Gdańsk University of Technology. The main goal of this project is to demonstrate a strong understanding of Object-Oriented Programming (OOP) principles, such as inheritance, polymorphism, encapsulation, and abstraction.

The application simulates a living ecosystem on a 2D grid. The world is populated by various species of animals and plants, each exhibiting unique behaviors, movement patterns, and interaction rules.

## Features
* **Turn-based Ecosystem:** All actions (movement, eating, breeding) are performed in turns, sorted by organism initiative and age.
* **Playable Character:** Includes a Human organism controlled by the player via keyboard inputs, featuring a unique, activatable special ability.
* **Complex Interactions:** Organisms interact upon collision based on strength. Interactions include fighting, escaping, reflecting attacks, and breeding.
* **Various Species:** Implementation of multiple animal types (Wolf, Sheep, Fox, Turtle, Antelope) and plant types (Grass, Guarana, Belladonna, etc.) with custom logic.
* **Data Persistence:** Ability to save the current state of the simulation to a file and load it to resume the simulation.

## Tech Stack
* Language: **C++**
* Paradigm: Object-Oriented Programming (OOP)
* UI: **Console (ASCII)**

## Architecture
The project heavily relies on OOP concepts. The core logic is managed by the `World` class, which holds a collection of organisms. Every living entity inherits from the abstract `Organism` class through intermediate abstract classes like `Animal` and `Plant`.Polymorphism is utilized extensively through overridden `action()` and `collision()` methods to define species-specific behaviors.
