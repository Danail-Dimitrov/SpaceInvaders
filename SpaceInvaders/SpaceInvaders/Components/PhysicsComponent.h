#pragma once

#include "../Constants.h"
#include "../Player.h"

class Player;

class PhysicsComponent
{
public:
	PhysicsComponent(const sf::Vector2u& windowSize) : windowSize(windowSize) {}

	void update(Player& player, float deltaTime);

private:
	sf::Vector2u windowSize; 
};