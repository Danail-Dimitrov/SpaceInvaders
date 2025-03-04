#include "Player.h"

Player::Player()
{
	this->initShipSprite();
	this->initEngineSprite();
	this->initEngineAnimationSprite();
	this->initKeyBindings();
}

Player::~Player()
{
	delete this->ship;
}

void Player::update()
{
	this->updateMovment();
}

void Player::render(sf::RenderTarget& target)
{
	this->ship->render(target);
}

void Player::initShipSprite()
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/Ship.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";

	sf::Sprite* sprite = new sf::Sprite(*texture);
	sprite->setScale({ 2.3f, 2.3f });
	sprite->setPosition({ 480, 860 });

	this->ship = new TextureNode(texture, sprite, { 0.f, 0.f });
}

void Player::initEngineSprite()
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/Engine.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	
	sf::Sprite* sprite = new sf::Sprite(*texture);
	sprite->setScale({ 2.3f, 2.3f });
	sprite->setPosition({ 480, 860 });

	this->ship->addChild(texture, sprite, { 0.f, 0.f });
}

void Player::initEngineAnimationSprite()
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/EngineAnimations.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";

	sf::Sprite* sprite = new sf::Sprite(*texture);
	sprite->setScale({ 2.3f, 2.3f });
	this->currentEngineFrame = sf::IntRect(sf::Vector2i(13, 30), sf::Vector2i(21, 6));
	sprite->setTextureRect(this->currentEngineFrame);
}

void Player::initKeyBindings()
{
	this->keyBindings[Constants::MOVE_UP] = sf::Keyboard::Key::W;
	this->keyBindings["DOWN"] = sf::Keyboard::Key::S;
	this->keyBindings["LEFT"] = sf::Keyboard::Key::A;
	this->keyBindings["RIGHT"] = sf::Keyboard::Key::D;
}

void Player::updateMovment()
{
	
}

void Player::updateMovment(const float dirX, const float dirY)
{

}

TextureNode* Player::getEngine()
{
	return this->ship->getChildren()[0];
}

TextureNode* Player::getEngineAnimations()
{
	return getEngine()->getChildren()[0];
}
