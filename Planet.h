#pragma once

class Planet {
	private:
		double xPosition, yPosition;
		double xSpeed, ySpeed;
		double mass;

	public:
		Planet(double xPos, double yPos, double xSpeed, double ySpeed, double mass) : xPosition(xPos), yPosition(yPos), xSpeed(xSpeed), ySpeed(ySpeed), mass(mass){}
		double getXPosition();
		double getYPosition();
		double getXSpeed();
		double getYSpeed();
		double getMass();

		void setYPosition(double position);
		void setXPosition(double position);
		void setYSpeed(double speed);
		void setXSpeed(double speed);


		double distance(Planet other);
		double magnetism(Planet other);
		double magnetismX(Planet other);
		double magnetismY(Planet other);



};