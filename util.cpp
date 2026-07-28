#include "util.h"

float deg_to_rad(float deg) {
    return deg * (numbers::pi / 180.0f);
}

float distance_between_vec2(Vector2 vec1, Vector2 vec2) {
    return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
}