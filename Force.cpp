#include "Force.h"

double Force::getForceX()
{
	return this->forceX;
}

double Force::getForceY()
{
	return this->forceY;
}

void Force::setForceX(double force)
{
	this->forceX = force;
}

void Force::setForceY(double force)
{
	this->forceY = force;
}
