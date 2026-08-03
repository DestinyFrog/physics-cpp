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
            // n = posB - posA / √(posA² + posB²)
            vec2 n = (node.B->position - node.A->position) / distance;

            // velocidade relativa de A em relação a B na direção normal
            // Vrel = (velA - velB) * n
            double v_rel = ((node.A->velocity - node.B->velocity) * n).collapse();

            // se {Vrel > 0} esta colidindo
            if (v_rel > 0) {
                // constante de restituicao
                double e = node.A->restitution * node.B->restitution;

                // Impulso
                // J = -(1 + e) * Vrel /
                //        1/mA + 1/mB
                double j = -(1 + e) * v_rel / (inv(node.A->mass) + inv(node.B->mass));

                // V = Vo + n * J/m
                node.A->velocity += n * (j / node.A->mass);
                node.B->velocity += n * (-j / node.B->mass);
            }

            // separa corpos sobrepostos
            double overlap = node.A->radius + node.B->radius - distance;
            node.A->position += n * (-overlap * 0.5);
            node.B->position += n * (overlap * 0.5);
        }
        else {
            // Força da Gravidade
            // G * (m1 * m2) / d²
            double F = G * ( node.A->mass * node.B->mass ) / pow(distance, 2);
            
            double rad = distance_vec.atan2();
            node.A->add_force(F, rad + numbers::pi);
            node.B->add_force(F, rad);
        }
    }
}
