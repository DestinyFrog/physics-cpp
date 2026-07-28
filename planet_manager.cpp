#include "planet_manager.h"

PlanetManager::PlanetManager() {
    planets = {};
}

void PlanetManager::add_planet(string name, Planet planet) {
    for (const auto& [key, planet2] : planets) {
        PlanetNode node = { name, key }
        nodes.push_back(node);
    }

    planets.insert(name, planet);
}

void PlanetManager::update() {
    for (int i = 0; i < nodes.size(); i++) {
        planets[nodes[i].planet1];
    }

    for (int i = 0; i < planets.size(); i++)
        planet[i].update();
}

void PlanetManager::draw() {
    for (int i = 0; i < planets.size(); i++)
        planet[i].draw();
}

void PlanetManager::mouse_button_down() {
    for (int i = 0; i < planets.size(); i++)
        planet[i].mouse_button_down();
}

void PlanetManager::mouse_button_up() {
    for (int i = 0; i < planets.size(); i++)
        planet[i].mouse_button_up();
}
