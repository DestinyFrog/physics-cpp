#include <raylib.h>
#include <cmath>
#include <iostream>

#include "planet_manager.h"
#include "planet.h"
#include "util.h"

using namespace std;

int main() {
    const double G = 6.6743f * pow(10, -11);

    const int width = 600;
    const int height = 600;
    
    PlanetManager manager = PlanetManager();
    
    const double earth_mass = 5.9722f * pow(10, 24);
    const double earth_radius = 6.371;
    Planet earth = Planet(width/2, height/2, earth_radius * 5, earth_mass * pow(10, -13), SKYBLUE);
    manager.add_planet(&earth);
    
    const double moon_mass = 7.35f * pow(10, 22);
    const double moon_radius = 1.737;
    Planet moon = Planet(width/4, height/4, moon_radius * 5, moon_mass * pow(10, -13), LIGHTGRAY);
    manager.add_planet(&earth);

    bool is_colliding = false;

    InitWindow(width, height, "Planetas");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            manager.mouse_button_down();

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            manager.mouse_button_up();

        double distance_x = earth.get_x() - moon.get_x();
        double distance_y = earth.get_y() - moon.get_y();
        double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
        double F = G * ( earth.get_mass() * moon.get_mass() ) / pow(distance, 2);
        double rad = atan2(distance_y, distance_x);

        earth.add_force(F, rad + numbers::pi);
        moon.add_force(F, rad);

        if (distance <= earth.get_radius() + moon.get_radius()) {
            if (is_colliding == false) {
                earth.clear_velocity();
                moon.clear_velocity();
            }

            is_colliding = true;
            earth.add_force(-F, rad + numbers::pi);
            moon.add_force(-F, rad);
        }
        else
            is_colliding = false;

        manager.update();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            manager.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}