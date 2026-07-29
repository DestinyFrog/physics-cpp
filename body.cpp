#include "body.h"

Body::Body() {
    result_force = { 0, 0 };
    velocity = { 0, 0 };
    acceleration = { 0, 0 };
    position = { 0, 0 };
    mass = 0;
    radius = 0;
}

void Body::set_mass(double mass) {
    this->mass = mass * std::pow(10, -9);
}

void Body::set_radius(double radius) {
    this->radius = radius * 5;
}

void Body::set_position(double x, double y) {
    this->position.x = x;
    this->position.y = y;
}

void Body::set_velocity(double x, double y) {
    this->velocity.x = x;
    this->velocity.y = y;
}

void Body::set_restitution(double restitution) {
    this->restitution = restitution;
}

double Body::get_x() {
    return position.x;
}

double Body::get_y() {
    return position.y;
}

double Body::get_velocity_x() {
    return velocity.x;
}
double Body::get_velocity_y() {
    return velocity.y;
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

void Body::inverse_velocity() {
    velocity.x *= -1;
    velocity.y *= -1;
}

void Body::move() {
    float delta_time = GetFrameTime();

    acceleration.x = result_force.x / mass; // ax = Fx / m
    acceleration.y = result_force.y / mass; // ay = Fy / m

    velocity.x += acceleration.x * delta_time; // Vx = Vox + ax * t
    velocity.y += acceleration.y * delta_time; // Vy = Voy + ay * t

    position.x += velocity.x * delta_time; // Sx = Sox + vx * t
    position.y += velocity.y * delta_time; // Sy = Soy + vy * t

    result_force.x = 0;
    result_force.y = 0;
}

void Body::add_force(double force, double angle) {
    result_force.x += std::cos(angle) * force; // Fx = cos(α) * F
    result_force.y += std::sin(angle) * force; // Fy = sin(α) * F
}