#include "gravity.h"

Gravity::Gravity() {
    G = 6.6743f * pow(10, -11);
}

void Gravity::add_body(Body* body) {
    for (auto body_b: bodies) {
        BodyNode node = { body, body_b };
        nodes.push_back(node);
    }
    bodies.push_back(body);
}

void Gravity::update() {
    for (auto node: nodes) {
        double distance_x = node.body_a->get_x() - node.body_b->get_x();
        double distance_y = node.body_a->get_y() - node.body_b->get_y();

        // d = √( x² + y² )
        double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));

        // rad = atan2( x, y )
        double rad = atan2(distance_y, distance_x);

        // G * (m1 * m2) / d²
        double F = G * ( node.body_a->get_mass() * node.body_b->get_mass() ) / pow(distance, 2);

        if (distance <= node.body_a->get_radius() + node.body_b->get_radius()) {
            if (node.is_colliding == false) {
                // Impulso/Momento
                double px = node.body_a->get_mass() * node.body_a->get_velocity_x();
                double py = node.body_a->get_mass() * node.body_a->get_velocity_y();
                
                
            }

            node.is_colliding = true;
            // node.body_a->add_force(-2 * F, rad + numbers::pi);
            // node.body_b->add_force(-2 * F, rad);
        }
        else {
            node.is_colliding = false;
            node.body_a->add_force(F, rad + numbers::pi);
            node.body_b->add_force(F, rad);
        }
    }
}
