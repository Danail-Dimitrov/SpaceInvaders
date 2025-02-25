#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	const double MS_PER_UPDATE = 16.0;

	sf::RenderWindow* window;
	short fps;

	void pollEvents();
	void update();
	void render();

	void initWindow();
	void initVariables();

	bool isRunning();
};

