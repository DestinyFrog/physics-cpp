#include "body.h"

Body::Body() {
    result_force = { 0, 0 };
    velocity = { 0, 0 };
    acceleration = { 0, 0 };
    position = { 0, 0 };
    mass = 0;
    radius = 0;
}

Body* Body::set_mass(double mass) {
    this->mass = mass * std::pow(10, -12);
    return this;
}

Body* Body::set_radius(double radius) {
    this->radius = radius * 5;
    return this;
}

Body* Body::set_position(double x, double y) {
    this->position.x = x;
    this->position.y = y;
    return this;
}

double Body::get_x() {
    return position.x;
}

double Body::get_y() {
    return position.y;
}

double Body::get_mass() {
    return mass;
}

double Body::get_radius() {
    return radius;
}

void Body::clear_velocity() {
    velocity.x = 0;
    velocity.y = 0;
}

void Body::move() {
    acceleration.x = result_force.x / mass;
    acceleration.y = result_force.y / mass;

    velocity.x += acceleration.x;
    velocity.y += acceleration.y;

    position.x += velocity.x;
    position.y += velocity.y;
}

void Body::add_force(double force, double angle) {
    result_force.x = std::cos(angle) * force; // Fx = cos(α) * F
    result_force.y = std::sin(angle) * force; // Fy = sin(α) * F
}