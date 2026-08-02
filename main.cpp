#include <raylib.h>

#include "gravity.hpp"
#include "planet.hpp"
#include "planet_factory.hpp"
#include "util.hpp"

using namespace std;

int main() {
    const int width = 700;
    const int height = 700;

    Gravity gravity = Gravity();
    PlanetFactory planet_factory = PlanetFactory(&gravity);

    InitWindow(width, height, "Planetas");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        planet_factory.update();
        gravity.update();

        BeginDrawing();
            ClearBackground(DARKGRAY);
            planet_factory.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}