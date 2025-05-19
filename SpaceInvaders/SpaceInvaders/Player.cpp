#include "Player.h"

Player::Player()
{
	this->initVariables();
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

void Player::addXVelocityMult(float x)
{
	this->velocityMultiplier.x += x;
	if (this->velocityMultiplier.x > this->maxVelocityMultiplier)
		this->velocityMultiplier.x = this->maxVelocityMultiplier;
	else if (this->velocityMultiplier.x < -1 * this->maxVelocityMultiplier)
		this->velocityMultiplier.x = -1 * this->maxVelocityMultiplier;
}

void Player::addYVelocityMult(float y)
{
	this->velocityMultiplier.y += y;
	if (this->velocityMultiplier.y > this->maxVelocityMultiplier)
		this->velocityMultiplier.y = this->maxVelocityMultiplier;
	else if (this->velocityMultiplier.y < -1 * this->maxVelocityMultiplier)
		this->velocityMultiplier.y = -1 * this->maxVelocityMultiplier;
}

void Player::initVariables()
{
	this->velocity = 0.f;
	this->maxVelocityMultiplier = 10.f;
}

void Player::initShipSprite()
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/Ship.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";

	sf::Sprite* sprite = new sf::Sprite(*texture);
	auto frame = sf::IntRect(sf::Vector2i(10, 12), sf::Vector2i(30, 28));
	sprite->setTextureRect(frame);
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
	auto frame = sf::IntRect(sf::Vector2i(12, 20), sf::Vector2i(30, 28));
	sprite->setTextureRect(frame);
	sprite->setScale({ 2.3f, 2.3f });

	this->ship->addChild(texture, sprite, { 5.f, 23.f });
}

void Player::initEngineAnimationSprite()
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/EngineAnimations.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";

	sf::Sprite* sprite = new sf::Sprite(*texture);
	auto frame = sf::IntRect(sf::Vector2i(14, 79), sf::Vector2i(21, 6));
	sprite->setTextureRect(frame);
	sprite->setScale({ 2.3f, 2.3f });
	this->ship->getChildren()[0]->addChild(texture, sprite, { 5.f, 24.f });
}

void Player::initKeyBindings()
{
	this->keyBindings[Constants::MOVE_UP] = sf::Keyboard::Key::W;
	this->keyBindings[Constants::MOVE_DOWN] = sf::Keyboard::Key::S;
	this->keyBindings[Constants::MOVE_LEFT] = sf::Keyboard::Key::A;
	this->keyBindings[Constants::MOVE_RIGHT] = sf::Keyboard::Key::D;
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(this->keyBindings[Constants::MOVE_UP]))
		this->addYVelocityMult(0.5f);
}

void Player::updateMovment()
{
	float newX = this->ship->getSprite()->getPosition().x + this->velocity * this->velocityMultiplier.x;
	float newY = this->ship->getSprite()->getPosition().y + this->velocity * this->velocityMultiplier.y;
	
	this->ship->move({ newX, newY });
}

TextureNode* Player::getEngine()
{
	return this->ship->getChildren()[0];
}

TextureNode* Player::getEngineAnimations()
{
	return getEngine()->getChildren()[0];
}
