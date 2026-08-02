#include "planet_factory.hpp"

PlanetFactory::PlanetFactory(Gravity* gravity) {
    this->gravity = gravity;
    this->aiming_start_position = { 0, 0 };
    this->aiming_position = { 0, 0 };
    this->state = IDLE;
}

void PlanetFactory::update() {
    bool planet_is_aiming = false;
    for (auto& planet: planets) {
        planet->update();
        if(planet->state == PlanetState::AIMING || planet->state == PlanetState::DRAGGING)
            planet_is_aiming = true;
    }

    switch (state) {
        case IDLE:
            if (!planet_is_aiming && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                state = AIMING;
                Vector2 mouse_pos = GetMousePosition();
                aiming_start_position.x = mouse_pos.x;
                aiming_start_position.y = mouse_pos.y;

                aiming_position.x = aiming_start_position.x;
                aiming_position.y = aiming_start_position.y;
            }
        break;
        case AIMING:
            Vector2 mouse_pos = GetMousePosition();
            aiming_position.x = mouse_pos.x;
            aiming_position.y = mouse_pos.y;

            if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
                state = IDLE;
                create_planet();
            }
        break;
    }
}

void PlanetFactory::draw() {
    for (auto& planet: planets)
        planet->draw();

    if (state == AIMING) {
        DrawLine(aiming_start_position.x, aiming_start_position.y, aiming_position.x, aiming_position.y, RED);

        double arrow_size = (aiming_position - aiming_start_position).pit();
        DrawCircleLines(aiming_start_position.x, aiming_start_position.y, arrow_size, RED);
    }
}

void PlanetFactory::create_planet() {
    double radius = (aiming_position - aiming_start_position).pit();
    double mass = pow(radius, 9);

    auto planet = std::make_unique<Planet>(SKYBLUE);
    planet->restitution = 0.0f;
    planet->mass = mass;
    planet->radius = radius;
    planet->position = aiming_start_position;

    gravity->add_body(planet.get());
    planets.push_back(std::move(planet));
}