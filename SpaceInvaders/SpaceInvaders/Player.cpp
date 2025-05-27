#include "Player.h"

Player::Player(PlayerInputComponent* inputComponent,
	PhysicsComponent* physicsComponent)
{
	this->inputComponent = inputComponent;
	this->physicsComponent = physicsComponent;

	this->initVariables();
	this->initShipSprite();
	this->initEngineSprite();
	this->initEngineAnimationSprite();
	this->initKeyBindings();
}

Player::~Player()
{
	delete this->ship;
	delete this->inputComponent;
	delete this->physicsComponent;
}

void Player::update(float deltaTime)
{
	this->inputComponent->update(*this, this->keyBindings);
	this->physicsComponent->update(*this, deltaTime);
}

void Player::render(sf::RenderTarget& target)
{
	this->ship->render(target);
}

void Player::addXVelocityMult(float x)
{
	this->velocity.x += x;
	if (this->velocity.x > this->maxVelocityMultiplier)
		this->velocity.x = this->maxVelocityMultiplier;
	else if (this->velocity.x < -1 * this->maxVelocityMultiplier)
		this->velocity.x = -1 * this->maxVelocityMultiplier;
}

void Player::addYVelocityMult(float y)
{
	this->velocity.y += y;
	if (this->velocity.y > this->maxVelocityMultiplier)
		this->velocity.y = this->maxVelocityMultiplier;
	else if (this->velocity.y < -1 * this->maxVelocityMultiplier)
		this->velocity.y = -1 * this->maxVelocityMultiplier;
}

void Player::initVariables()
{
	this->maxVelocityMultiplier = 6.f;
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

TextureNode* Player::getEngine()
{
	return this->ship->getChildren()[0];
}

TextureNode* Player::getEngineAnimations()
{
	return getEngine()->getChildren()[0];
}
