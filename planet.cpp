#include "planet.h"

Planet::Planet(Color color): Body() {
    this->mouse_offset = { 0, 0 };
    this->state = IDLE;
    this->color = color;
}

void Planet::update() {
    switch (state) {
        case IDLE:
            move();
        break;

        case DRAGGING:
            Vector2 mouse_pos = GetMousePosition();
            position.x = mouse_pos.x + mouse_offset.x;
            position.y = mouse_pos.y + mouse_offset.y;
        break;
    }
}

void Planet::draw() {
    DrawCircle(position.x, position.y, radius, color);
}

void Planet::mouse_button_down() {
    if (state == DRAGGING)
        return;

    Vector2 mouse_pos = GetMousePosition();
    mouse_offset.x = position.x - mouse_pos.x;
    mouse_offset.y = position.y - mouse_pos.y;

    double distance_mouse_body = sqrt(pow(mouse_offset.x, 2) + pow(mouse_offset.y, 2));

    if (distance_mouse_body <= radius)
        state = DRAGGING;
}

void Planet::mouse_button_up() {
    if (state == DRAGGING)
        state = IDLE;
}
