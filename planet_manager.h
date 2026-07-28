#ifndef PLANET_MANAGER_H_
#define PLANET_MANAGER_H_

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#include "planet.h"

struct PlanetNode {
    Planet* planet1;
    Planet* planet2;
    bool is_colliding;
};

class PlanetManager {
    private:
    vector<Planet*> planets;
    vector<PlanetNode> nodes;

    public:
    PlanetManager();
    void add_planet(Planet* planet); 
    void draw();
    void update();
    void mouse_button_down();
    void mouse_button_up();
};

#endif /* PLANET_MANAGER_H_ */