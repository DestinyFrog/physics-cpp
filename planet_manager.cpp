#include "planet_manager.h"

PlanetManager::PlanetManager() {
    planets = {};
}

void PlanetManager::add_planet(Planet* planet) {
    for (int i = 0; i < static_cast<int>(planets.size()); i++) {
        PlanetNode node = { planet, planets[i] };
        nodes.push_back(node);
    }

    planets.push_back(planet);
}

void PlanetManager::update() {
    Planet* planet_a;
    Planet* planet_b;
    for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
        planet_a = nodes[i].planet1;
        planet_b = nodes[i].planet2;

        double distance_x = planet_a->get_x() - planet_b->get_x();
        double distance_y = planet_a->get_y() - planet_b->get_y();
        double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
        double F = G * ( planet_a->get_mass() * planet_b->get_mass() ) / pow(distance, 2);
        double rad = atan2(distance_y, distance_x);

        planet_a->add_force(F, rad + numbers::pi);
        planet_b->add_force(F, rad);

        if (distance <= planet_a->get_radius() + planet_b->get_radius()) {
            if (nodes[i].is_colliding == false) {
                planet_a->clear_velocity();
                planet_b->clear_velocity();
            }

            nodes[i].is_colliding = true;
            planet_a->add_force(-F, rad + numbers::pi);
            planet_b->add_force(-F, rad);
        }
        else
            nodes[i].is_colliding = false;
    }


    for (int i = 0; i < static_cast<int>(planets.size()); i++)
        planets[i]->update();
}

void PlanetManager::draw() {
    for (int i = 0; i < static_cast<int>(planets.size()); i++)
        planets[i]->draw();
}

void PlanetManager::mouse_button_down() {
    for (int i = 0; i < static_cast<int>(planets.size()); i++)
        planets[i]->mouse_button_down();
}

void PlanetManager::mouse_button_up() {
    for (int i = 0; i < static_cast<int>(planets.size()); i++)
        planets[i]->mouse_button_up();
}
