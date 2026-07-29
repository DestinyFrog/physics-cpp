#include <raylib.h>
#include <cmath>
#include <iostream>

#include "gravity.h"
#include "planet.h"
#include "util.h"

using namespace std;

int main() {
    const int width = 600;
    const int height = 600;

    Planet earth = Planet(SKYBLUE);
    earth.set_mass(5.97f * pow(10, 24));
    earth.set_radius(6.371f);
    earth.set_position(width/2, height/2);

    Planet mars = Planet(ORANGE);
    mars.set_mass(6.41f * pow(10, 23));
    mars.set_radius(3.389f);
    mars.set_position(width/4*3, height/4);

    Planet moon = Planet(LIGHTGRAY);
    moon.set_mass(7.35f * pow(10, 22));
    moon.set_radius(1.737f);
    moon.set_position(width/4, height/4);

    Gravity gravity = Gravity();
    gravity.add_body(&earth);
    gravity.add_body(&mars);
    gravity.add_body(&moon);

    InitWindow(width, height, "Planetas");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            earth.mouse_button_down();
            mars.mouse_button_down();
            moon.mouse_button_down();
        }

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
            moon.mouse_button_up();
            mars.mouse_button_up();
            earth.mouse_button_up();
        }

        gravity.update();
        earth.update();
        mars.update();
        moon.update();

        BeginDrawing();
            ClearBackground(DARKGRAY);
            earth.draw();
            mars.draw();
            moon.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}