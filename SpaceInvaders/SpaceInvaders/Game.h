#pragma once
#include "Player.h"
#include "Components/PhysicsComponent.h"
#include "Components/PlayerInputComponent.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	Player* player;

	sf::RenderWindow* window;
	short fps;

	void pollEvents();
	void update(float dt);
	void render();

	void initWindow();
	void initVariables();
	void initPlayer();

	bool isRunning();
};

