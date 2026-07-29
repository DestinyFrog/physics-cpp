#include <raylib.h>
#include <cmath>
#include <vector>

#include "gravity.h"
#include "planet.h"
#include "util.h"

using namespace std;

int main() {
    const int width = 200;
    const int height = 200;

    Planet earth = Planet(SKYBLUE);
    earth.set_restitution(0);
    earth.set_mass(5.97f * pow(10, 24));
    earth.set_radius(6.371f);
    earth.set_position(width/2, height/2);

    Planet mars = Planet(ORANGE);
    mars.set_restitution(0);
    mars.set_mass(6.41f * pow(10, 23));
    mars.set_radius(3.389f);
    mars.set_position(width/4*3, height/4);

    Planet moon = Planet(LIGHTGRAY);
    moon.set_mass(7.35f * pow(10, 22));
    moon.set_radius(1.737f);
    moon.set_position(width/4, height/4);

    vector<Planet> planets = { earth, mars };

    Gravity gravity = Gravity();
    for (int i = 0; i < static_cast<int>(planets.size()); i++)
        gravity.add_body(&planets[i]);

    InitWindow(width, height, "Planetas");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            for (int i = 0; i < static_cast<int>(planets.size()); i++)
                planets[i].left_mouse_button_down();

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            for (int i = 0; i < static_cast<int>(planets.size()); i++)
                planets[i].right_mouse_button_down();

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            for (int i = 0; i < static_cast<int>(planets.size()); i++)
                planets[i].left_mouse_button_up();

        if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT))
            for (int i = 0; i < static_cast<int>(planets.size()); i++)
                planets[i].right_mouse_button_up();

        gravity.update();

        for (int i = 0; i < static_cast<int>(planets.size()); i++)
            planets[i].update();

        BeginDrawing();
            ClearBackground(DARKGRAY);
            for (int i = 0; i < static_cast<int>(planets.size()); i++)
                planets[i].draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}