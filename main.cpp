#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlanetSystem.h"
using namespace std;
int main()
{
	int width = 600;
	int height = 600;
	double diameter = 5.0E11;
	sf::RenderWindow window(sf::VideoMode(width, height), "N-body simulation!");
	sf::Clock planetTimer;
	sf::Clock drawTimer;
	sf::Time time;
	int planetUpdateRate = 1000 / 60;
	int drawrate = 1000 / 30;

	vector<Planet> planets;
	Planet sun(538771.2647179796, 311728.01914265234, 0.15944610708562912, 0.15099663888466472, 1.989E30);
	Planet mercurius(-2.3423738558153862E10, -5.363391883276512E10, 43168.9924212314, -19555.612648233368, 3.302E23);
	Planet venus(-1.2257733349672739E10, 1.0688994731967513E11, -34980.88986158969, -3903.1360711941647, 4.869E24);
	Planet earth(7.649815710400691E10, 1.2825871174194992E11, -25608.972746907584, 15340.707015973465, 5.974E24);
	Planet mars(1.9433739848583844E11, 1.1855926503806793E11, -12591.918312354934, 20580.315270396313, 6.419E23);
	planets.push_back(sun);
	planets.push_back(mercurius);
	planets.push_back(venus);
	planets.push_back(earth);
	planets.push_back(mars);
	PlanetSystem system(planets, 5.0E11);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			time = planetTimer.getElapsedTime();
		if (time.asMilliseconds() > planetUpdateRate) {
			system.update(2000);
			planetTimer.restart();
		}
		time = drawTimer.getElapsedTime();
		if (time.asMilliseconds() > drawrate) {
			window.clear();
			for (int i = 0; i < planets.size(); i++) {
				sf::CircleShape shape(10, 10);
				shape.setFillColor(sf::Color::Green);
				shape.setPosition(width / 2 + width * planets[i].getXPosition() /diameter , height / 2  + height * planets[i].getYPosition() / diameter);
				window.draw(shape);
			}

			window.display();
		}
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}

