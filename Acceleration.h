#pragma once
class Acceleration {
private:
	double xAcceleration;
	double yAcceleration;

public:
	double getXAcceleration();
	double getYAcceleration();
	void setXAcceleration(double acceleration);
	void setYAcceleration(double acceleration);
};