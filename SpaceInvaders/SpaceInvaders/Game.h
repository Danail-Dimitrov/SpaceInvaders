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
	// Player
	Player* player;

	// Enemies
	// std::vector<Enemy*> enemies; // Placeholder for future enemy implementation

	// Window
	sf::RenderWindow* window;
	short fps;

	// Updates
	void pollEvents();
	void update(float dt);
	
	// Draws
	void render();

	// Inits
	void initWindow();
	void initVariables();
	void initPlayer();

	// Getters
	bool isRunning();
};

