#ifndef UTIL_H_
#define UTIL_H_

#include <cmath>

double inv(double x);

struct vec2 {
    double x;
    double y;

    vec2* operator+=(const vec2& b);
    vec2* operator=(const double& b);
    vec2 abs();
    double atan2();
    double pit();
    double collapse();
};

vec2 operator+(const vec2& a, const vec2& other);
vec2 operator-(const vec2& a, const vec2& b);
vec2 operator*(const vec2& a, const vec2& b);
vec2 operator*(const vec2& a, const double& b);
vec2 operator/(const vec2& a, const vec2& b);
vec2 operator/(const vec2& a, const double& b);

#endif /* UTIL_H_ */