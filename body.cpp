#include "body.hpp"

Body::Body() {
    result_force = { 0, 0 };
    velocity = { 0, 0 };
    acceleration = { 0, 0 };
    position = { 0, 0 };
    mass = 0;
    radius = 0;
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

    acceleration = result_force / mass;     // a = F / m
    velocity += acceleration * delta_time;  // V = Vo + a * t
    position += velocity * delta_time;      // S = So + v * t

    result_force.x = 0;
    result_force.y = 0;
}

void Body::add_force(double force, double angle) {
    result_force.x += std::cos(angle) * force; // Fx = cos(α) * F
    result_force.y += std::sin(angle) * force; // Fy = sin(α) * F
}