#pragma once
#include <random>

#include "Player.h"
#include "Enemies/Enemy.h"

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
	sf::Texture* enemyTexture;
	std::vector<Enemy*> enemies;
	sf::Clock enemySpawnClock;
	float enemySpawnDelay = 0.5f;
	size_t maxEnemies;

	// Window
	sf::RenderWindow* window;
	short fps;

	// Updates
	void pollEvents();
	void update(float dt);
	void spawnEnemies();

	// Draws
	void render();
	void renderEnemies();

	// Inits
	void initWindow();
	void initVariables();
	void initPlayer();
	void initEnemies();

	// Getters
	bool isRunning();
};

