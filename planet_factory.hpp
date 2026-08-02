#ifndef PLANET_FACTORY_H_
#define PLANET_FACTORY_H_

#include <vector>
#include <cmath>
#include <memory>
#include <raylib.h>

#include "util.hpp"
#include "planet.hpp"
#include "gravity.hpp"

class PlanetFactory {
    private:
    Gravity* gravity;
    vector<std::unique_ptr<Planet>> planets;
    vec2 aiming_start_position;
    vec2 aiming_position;
    enum {
        IDLE,
        AIMING
    } state;

    void create_planet();

    public:
    PlanetFactory(Gravity *gravity);
    void update();
    void draw();
};

#endif /* PLANET_FACTORY_H_ */