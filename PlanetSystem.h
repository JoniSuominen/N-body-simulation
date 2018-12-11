#include <iostream>
#include <vector>
#include "Planet.h"

using namespace std;
class PlanetSystem {
	private:
		double diameter;
		vector<Planet> & planets;

	public:
		PlanetSystem(vector<Planet> &planets, double diameter) : planets(planets), diameter(diameter){}
		vector<Planet> getPlanets();
		void update(double time);
};