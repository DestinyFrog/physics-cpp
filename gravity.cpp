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
        double distance = distance_between_node(&node);
        double rad = angle_between_node(&node);

        // G * (m1 * m2) / d²
        double F = G * ( node.body_a->get_mass() * node.body_b->get_mass() ) / pow(distance, 2);

        node.body_a->add_force(F, rad + numbers::pi);
        node.body_b->add_force(F, rad);

        if (distance <= node.body_a->get_radius() + node.body_b->get_radius()) {
            if (node.is_colliding == false) {
                // node.body_a->clear_velocity();
                // node.body_b->clear_velocity();
            }

            node.is_colliding = true;
            node.body_a->add_force(-F, rad + numbers::pi);
            node.body_b->add_force(-F, rad);
        }
        else
            node.is_colliding = false;
    }
}

// d = √( x² + y² )
double Gravity::distance_between_node(BodyNode* node) {
    double distance_x = node->body_a->get_x() - node->body_b->get_x();
    double distance_y = node->body_a->get_y() - node->body_b->get_y();
    return sqrt(pow(distance_x, 2) + pow(distance_y, 2));
}

// rad = atan2( x, y )
double Gravity::angle_between_node(BodyNode* node) {
    double distance_x = node->body_a->get_x() - node->body_b->get_x();
    double distance_y = node->body_a->get_y() - node->body_b->get_y();
    return atan2(distance_y, distance_x);
}