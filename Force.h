#pragma once
class Force {
private:
	double forceX = 0;
	double forceY = 0;

public:
	double getForceX();
	double getForceY();
	void setForceX(double force);
	void setForceY(double force);
};