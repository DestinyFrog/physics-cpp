#include "planet.hpp"

Planet::Planet(Color color): Body() {
    this->mouse_offset = { 0, 0 };
    this->arrow_position = { 0, 0 };
    this->state = IDLE;
    this->color = color;
    this->is_hovering = false;
}

void Planet::update() {
    calc_if_hovering();

    switch (state) {
        case PAUSED:
            // nothing
        break;
        case IDLE: {
            move();

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && is_hovering)
                state = DRAGGING;

            if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && is_hovering)
                state = AIMING;
        } break;
        case DRAGGING: {
            if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
                state = IDLE;

            Vector2 mouse_pos = GetMousePosition();
            position = { mouse_pos.x, mouse_pos.y };
        } break;
        case AIMING: {
            arrow_position = GetMousePosition();

            if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT)) {
                Vector2 mouse_pos = GetMousePosition();
                vec2 distance_vec = { position.x - mouse_pos.x, position.y - mouse_pos.y };
                add_force(distance_vec.pit() * pow(mass, 1.1), distance_vec.atan2() + numbers::pi);
                velocity = 0;
                acceleration = 0;
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

    if (is_hovering) {
        const static int font_size = 16;
        DrawText(TextFormat("Posição:    x: %.1f y: %.1f", position.x, position.y), 10, 10, font_size, DARKGRAY);
        DrawText(TextFormat("Velocidade: x: %.1f y: %.1f", velocity.x, velocity.y), 10, 10 + font_size, font_size, DARKGRAY);
        DrawText(TextFormat("Aceleração: x: %.1f y: %.1f", acceleration.x, acceleration.y), 10, 10 + font_size*2, font_size, DARKGRAY);
        DrawText(TextFormat("Massa: %.1f%", mass), 10, 10 + font_size*3, font_size, DARKGRAY);
    }
}

void Planet::calc_if_hovering() {
    Vector2 mouse_pos = GetMousePosition();
    vec2 distance_vec = { position.x - mouse_pos.x, position.y - mouse_pos.y };
    is_hovering = distance_vec.pit() <= radius;
}

void Planet::pause() {
    state = PAUSED;
}

void Planet::resume() {
    if (state == PAUSED)
        state = IDLE;
}