#include "Player.h"

Player::Player()
{
	this->initTextures();
	this->initSprites();
}

Player::~Player()
{
	delete this->shipSprite;
	delete this->engineSprite;
	delete this->engineAnimationSprite;
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(*this->shipSprite);
	target.draw(*this->engineSprite);
	target.draw(*this->engineAnimationSprite);
}

void Player::initTextures()
{
	if (!this->shipTexture.loadFromFile("Textures/Ship.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	
	if (!this->engineTexture.loadFromFile("Textures/Engine.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";

	if (!this->engineAnimationTexture.loadFromFile("Textures/EngineAnimations.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
}

void Player::initSprites()
{
	this->initShipSprite();
	this->initEngineSprite();
	this->initEngineAnimationSprite();
}

void Player::initShipSprite()
{
	this->shipSprite = new sf::Sprite(this->shipTexture);
	this->shipSprite->setScale({ 2.3f, 2.3f });
	this->shipSprite->setPosition({ 480, 860 });
}

void Player::initEngineSprite()
{
	this->engineSprite = new sf::Sprite(this->engineTexture);
	this->engineSprite->setScale({ 2.3f, 2.3f });
	this->engineSprite->setPosition({ 480, 860 });
}

void Player::initEngineAnimationSprite()
{
	this->engineAnimationSprite = new sf::Sprite(this->engineAnimationTexture);
	this->engineAnimationSprite->setScale({ 2.3f, 2.3f });
	this->currentFrame = sf::IntRect(sf::Vector2i(13, 30), sf::Vector2i(21, 6));
	this->engineAnimationSprite->setTextureRect(this->currentFrame);
	this->engineAnimationSprite->setPosition({ 510, 930 });
}
