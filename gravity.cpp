#include "gravity.hpp"

Gravity::Gravity() {
    G = 6.6743f * pow(10, -11);
}

void Gravity::add_body(Body* body) {
    for (auto B: bodies) {
        BodyNode node = { body, B };
        nodes.push_back(node);
    }
    bodies.push_back(body);
}

void Gravity::update() {
    for (auto node: nodes) {
        vec2 distance_vec = node.A->position - node.B->position; 
        double distance = distance_vec.pit();

        if (distance == 0)
            continue;

        if (distance <= node.A->radius + node.B->radius) {
            // vetor normal unitário de A para B
            vec2 n = (node.B->position - node.A->position) / distance;

            // velocidade relativa de A em relação a B na direção normal
            vec2 vel_rel_vec = node.A->velocity - node.B->velocity;
            double v_rel = vel_rel_vec.x * n.x + vel_rel_vec.y * n.y;

            if (v_rel > 0) {
                double e = node.A->restitution * node.B->restitution;
                double j = -(1 + e) * v_rel / (inv(node.A->mass) + inv(node.B->mass));

                node.A->velocity += n * (j / node.A->mass);
                node.B->velocity += n * (-j / node.B->mass);
            }

            // separa corpos sobrepostos
            double overlap = node.A->radius + node.B->radius - distance;
            node.A->position += n * (-overlap * 0.5);
            node.B->position += n * (overlap * 0.5);
        }
        else {
            double rad = distance_vec.atan2();

            // G * (m1 * m2) / d²
            double F = G * ( node.A->mass * node.B->mass ) / pow(distance, 2);

            node.A->add_force(F, rad + numbers::pi);
            node.B->add_force(F, rad);
        }
    }
}
