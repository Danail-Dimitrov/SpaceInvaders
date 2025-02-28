#pragma once
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	const double MS_PER_UPDATE = 16.0;

	Player* player;

	sf::RenderWindow* window;
	short fps;

	void pollEvents();
	void update();
	void render();

	void initWindow();
	void initVariables();
	void initPlayer();

	bool isRunning();
};

