#include "PlanetSystem.h"
#include "Planet.h"
#include "Force.h"
#include "Acceleration.h"
#include <iostream>
using namespace std;

vector<Planet> PlanetSystem::getPlanets()
{
	return this->planets;
}

void PlanetSystem::update(double time)
{
	vector<Force> forces;
	vector<Acceleration> accelerations;

	for (int i = 0; i < this->planets.size(); i++) {
		Force force;
		Acceleration acceleration;
		forces.push_back(force);
		accelerations.push_back(acceleration);

		for (int j = 0; j < this->planets.size(); j++) {
			if (i != j) {
				forces.at(i).setForceX(forces.at(i).getForceX() + this->planets.at(i).magnetismX(this->planets.at(j)));
				forces.at(i).setForceY(forces.at(i).getForceY() + this->planets.at(i).magnetismY(this->planets.at(j)));
			}
		}

		accelerations.at(i).setXAcceleration(forces.at(i).getForceX() / this->planets.at(i).getMass());
		accelerations.at(i).setYAcceleration(forces.at(i).getForceY() / this->planets.at(i).getMass());

		double newXSpeed = this->planets.at(i).getXSpeed() + time * accelerations.at(i).getXAcceleration();
		double newYSpeed = this->planets.at(i).getYSpeed() + time * accelerations.at(i).getYAcceleration();
		this->planets.at(i).setXSpeed(newXSpeed);
		this->planets.at(i).setYSpeed(newYSpeed);
 	}

	for (int i = 0; i < this->planets.size(); i++) {
		double newXPosition = this->planets.at(i).getXPosition() + time * this->planets.at(i).getXSpeed();
		double newYPosition = this->planets.at(i).getYPosition() + time * this->planets.at(i).getYSpeed();
		planets.at(i).setXPosition(newXPosition);
		planets.at(i).setYPosition(newYPosition);
	}
}
