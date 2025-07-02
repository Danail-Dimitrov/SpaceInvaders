#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
	Enemy(sf::Texture* texture, sf::Vector2f position);
	~Enemy();

	void update(float deltaTime);
	void render(sf::RenderTarget& target);

	// Mutators
	// Returns if enemy is still alive after taking damage
	bool takeDmgage(int damage);

	// Accessors
	sf::Vector2f getPosition() const { return this->sprite->getPosition(); }
	sf::FloatRect getGlobalBounds() const { return this->sprite->getGlobalBounds(); }

private:
	// Sprite
	sf::Sprite* sprite;

	// Health
	int health;

	// Movement
	float movementSpeed;

	void initSprite(sf::Texture* texture, sf::Vector2f position);
	void initVariables();
};