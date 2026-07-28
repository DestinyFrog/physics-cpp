#include <raylib.h>
#include <cmath>
#include <iostream>

#include "planet_manager.h"
#include "planet.h"
#include "util.h"

using namespace std;

int main() {
    const int width = 600;
    const int height = 600;

    const double earth_mass = 5.97f * pow(10, 24);
    const double earth_radius = 6.371f;
    Planet earth = Planet(width/2, height/2, earth_radius * 5, earth_mass * pow(10, -13), SKYBLUE);
    
    const double moon_mass = 7.35f * pow(10, 22);
    const double moon_radius = 1.737f;
    Planet moon = Planet(width/4, height/4, moon_radius * 5, moon_mass * pow(10, -13), LIGHTGRAY);

    const double mars_mass = 6.41f * pow(10, 23);
    const double mars_radius = 3.389f;
    Planet mars = Planet(width/4*3, height/4, mars_radius * 5, mars_mass * pow(10, -13), ORANGE);

    PlanetManager manager = PlanetManager();
    manager.add_planet(&earth);
    manager.add_planet(&moon);
    manager.add_planet(&mars);

    InitWindow(width, height, "Planetas");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            manager.mouse_button_down();

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            manager.mouse_button_up();

        manager.update();

        BeginDrawing();
            ClearBackground(DARKGRAY);
            manager.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}