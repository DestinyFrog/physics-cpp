#include "planet.hpp"

Planet::Planet(Color color): Body() {
    this->mouse_offset = { 0, 0 };
    this->arrow_position = { 0, 0 };
    this->state = IDLE;
    this->color = color;
}

void Planet::update() {
    switch (state) {
        case PAUSED:
            // nothing
        break;
        case IDLE: {
            move();

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                Vector2 mouse_pos = GetMousePosition();
                mouse_offset.x = position.x - mouse_pos.x;
                mouse_offset.y = position.y - mouse_pos.y;

                double distance_mouse_body = sqrt(pow(mouse_offset.x, 2) + pow(mouse_offset.y, 2));
                if (distance_mouse_body <= radius) {
                    state = DRAGGING;
                }
            }

            if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
                Vector2 mouse_pos = GetMousePosition();
                double distance_mouse_body = sqrt(pow(position.x - mouse_pos.x, 2) + pow(position.y - mouse_pos.y, 2));
                if (distance_mouse_body <= radius)
                    state = AIMING;
            }
        } break;
        case DRAGGING: {
            Vector2 mouse_pos = GetMousePosition();
            position.x = mouse_pos.x + mouse_offset.x;
            position.y = mouse_pos.y + mouse_offset.y;

            if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
                state = IDLE;
        } break;
        case AIMING: {
            arrow_position = GetMousePosition();

            if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT)) {
                Vector2 mouse_pos = GetMousePosition();
                double distance_x = position.x - mouse_pos.x;
                double distance_y = position.y - mouse_pos.y;
                double distance_mouse_body = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
                double angle_mouse_body = atan2(distance_y, distance_x);
                add_force(distance_mouse_body * pow(mass, 1.1), angle_mouse_body + numbers::pi);
                velocity.x = 0;
                velocity.y = 0;
                acceleration.x = 0;
                acceleration.y = 0;
                state = IDLE;
            }
        } break;
    }
}

void Planet::draw() {
    DrawCircle(position.x, position.y, radius, color);

    if (state == AIMING) {
        DrawLine(position.x, position.y, arrow_position.x, arrow_position.y, RED);
        DrawCircle(arrow_position.x, arrow_position.y, 3, RED);
    }
}

void Planet::pause() {
    state = PAUSED;
}

void Planet::resume() {
    if (state == PAUSED)
        state = IDLE;
}