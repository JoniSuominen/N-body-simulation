#include "Planet.h"
#include <iostream>
#include <math.h>
using namespace std;

double Planet::getXPosition()
{
	return xPosition;
}

double Planet::getYPosition()
{
	return yPosition;
}

double Planet::getXSpeed()
{
	return xSpeed;
}

double Planet::getYSpeed()
{
	return ySpeed;
}
double Planet::getMass()
{
	return mass;
}

void Planet::setYPosition(double position)
{
	this->yPosition = position;
}

void Planet::setXPosition(double position)
{
	this->xPosition = position;
}

void Planet::setYSpeed(double speed)
{
	this->ySpeed = speed;
}

void Planet::setXSpeed(double speed)
{
	this->xSpeed = speed;
}


double Planet::distance(Planet other)
{
	return sqrt(pow(other.getXPosition() - this->getXPosition(), 2) + pow((other.getYPosition() - this->getYPosition()),2));
}

double Planet::magnetism(Planet other)
{
	return 6.67384e-11 * (this->getMass() * other.getMass()) / (distance(other) * distance(other));
}

double Planet::magnetismX(Planet other)
{
	return magnetism(other) * (other.getXPosition() - this->xPosition) / distance(other);
}

double Planet::magnetismY(Planet other)
{
	return magnetism(other) * (other.getYPosition() - this->yPosition) / distance(other);
}
