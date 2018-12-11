#include "Acceleration.h"
#pragma once

double Acceleration::getXAcceleration()
{
	return this->xAcceleration;
}

double Acceleration::getYAcceleration()
{
	return this->yAcceleration;
}

void Acceleration::setXAcceleration(double acceleration)
{
	this->xAcceleration = acceleration;
}

void Acceleration::setYAcceleration(double acceleration)
{
	this-> yAcceleration = acceleration;
}
