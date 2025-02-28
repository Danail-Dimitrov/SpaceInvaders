#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include<iostream>

class Player
{
public:
	Player();
	~Player();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Sprite* shipSprite;
	sf::Texture shipTexture;

	sf::Sprite* engineSprite;
	sf::Texture engineTexture;

	sf::Sprite* engineAnimationSprite;
	sf::Texture engineAnimationTexture;
	sf::IntRect currentFrame;

	void initTextures();
	void initSprites();
	void initShipSprite();
	void initEngineSprite();
	void initEngineAnimationSprite();
};

