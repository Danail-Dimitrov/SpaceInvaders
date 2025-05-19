#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

#include "Utilities/TextureNode.h"
#include "Constants.h"

class Player
{
public:
	Player();
	~Player();

	void update();
	void render(sf::RenderTarget& target);

	void addXVelocityMult(float x);
	void addYVelocityMult(float y);

private:
	// Sprites
	TextureNode* ship;
	sf::IntRect currentEngineFrame;

	// Key bindings
	std::map<std::string, sf::Keyboard::Key> keyBindings;

	// Movment
	sf::Vector2f velocityMultiplier;
	float maxVelocityMultiplier;
	float velocity;

	// Inits
	void initVariables();
	void initShipSprite();
	void initEngineSprite();
	void initEngineAnimationSprite();
	void initKeyBindings();

	// Updates
	void updateInput();
	void updateMovment();

	// Getters
	TextureNode* getEngine();
	TextureNode* getEngineAnimations();
};