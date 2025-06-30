#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
	Enemy(const sf::Texture& texture);
	~Enemy();

	void update(float deltaTime);
	void render(sf::RenderTarget& target);

	// Mutators
	// Returns if enemy is still alive after taking damage
	bool takeDmgage(int damage);

private:
	// Sprite
	sf::Sprite* sprite;

	// Health
	int health;

	void initVariables();
};