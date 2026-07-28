#ifndef PLANET_MANAGER_H_
#define PLANET_MANAGER_H_

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#include "planet.h"

struct PlanetNode {
    string planet1;
    string planet2;
    bool is_colliding;
};

class PlanetManager {
    private:
    unordered_map<string, Planet> planets;
    vector<PlanetNode> nodes;

    public:
    PlanetManager();
    void add_planet(string name, Planet planet); 
    void draw();
    void update();
    void mouse_button_down();
    void mouse_button_up();
};

#endif /* PLANET_MANAGER_H_ */