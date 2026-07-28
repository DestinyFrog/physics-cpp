#include "planet.h"

Planet::Planet(float x, float y, double radius, double mass, Color color) {
    this->mass = mass;
    this->position = { x, y };
    this->velocity = { 0, 0 };
    this->result_force = { 0, 0 };
    this->acceleration = { 0, 0 };
    this->mouse_offset = { 0, 0 };
    this->radius = radius;
    this->state = IDLE;
    this->color = color;
}

void Planet::update() {
    switch (state) {
        case IDLE:
            acceleration.x = result_force.x / mass;
            acceleration.y = result_force.y / mass;

            velocity.x += acceleration.x;
            velocity.y += acceleration.y;

            position.x += velocity.x;
            position.y += velocity.y;
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
    double distance_mouse_planet = sqrt(pow(mouse_offset.x, 2) + pow(mouse_offset.y, 2));

    if (distance_mouse_planet <= radius) {
        state = DRAGGING;
        acceleration.x = 0;
        acceleration.y = 0;
    }
}

void Planet::mouse_button_up() {
    if (state == DRAGGING)
        state = IDLE;
}

void Planet::add_force(double force, double angle) {
    result_force.x = static_cast<float>(cos(angle) * force);
    result_force.y = static_cast<float>(sin(angle) * force);
}

double Planet::get_mass() {
    return mass;
}

Vector2 Planet::get_position() {
    return position;
}

double Planet::get_x() {
    return static_cast<double>(position.x);
}

double Planet::get_y() {
    return static_cast<double>(position.y);
}

double Planet::get_radius() {
    return radius;
}

void Planet::clear_velocity() {
    this->velocity.x = 0;
    this->velocity.y = 0;
}