#include "util.hpp"

double inv(double x) {
    return 1.0f / x;
}

vec2 operator+(const vec2& a, const vec2& b) {
    vec2 res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

vec2* vec2::operator+=(const vec2& b) {
    this->x += b.x;
    this->y += b.y;
    return this;
}

vec2 operator-(const vec2& a, const vec2& b) {
    vec2 res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return res;
}

vec2 operator*(const vec2& a, const vec2& b) {
    vec2 res;
    res.x = a.x * b.x;
    res.y = a.y * b.y;
    return res;
}

vec2 operator*(const vec2& a, const double& b) {
    vec2 res;
    res.x = a.x * b;
    res.y = a.y * b;
    return res;
}

vec2 operator/(const vec2& a, const vec2& b) {
    vec2 res;
    res.x = a.x / b.x;
    res.y = a.y / b.y;
    return res;
}

vec2 operator/(const vec2& a, const double& b) {
    vec2 res;
    res.x = a.x / b;
    res.y = a.y / b;
    return res;
}

vec2 vec2::abs() {
    vec2 res;
    res.x = std::abs(x);
    res.y = std::abs(y);
    return res;
}

double vec2::atan2() {
    return std::atan2(y, x);
}

double vec2::pit() {
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}