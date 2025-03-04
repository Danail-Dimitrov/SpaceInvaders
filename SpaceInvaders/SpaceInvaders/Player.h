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

private:
	TextureNode* ship;
	sf::IntRect currentEngineFrame;
	std::map<std::string, sf::Keyboard::Key> keyBindings;

	void initShipSprite();
	void initEngineSprite();
	void initEngineAnimationSprite();
	void initKeyBindings();

	void updateMovment();
	void updateMovment(const float dirX, const float dirY);

	TextureNode* getEngine();
	TextureNode* getEngineAnimations();
};

