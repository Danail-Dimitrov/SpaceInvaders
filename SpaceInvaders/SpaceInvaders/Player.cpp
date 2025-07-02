#include "Player.h"

Player::Player(PlayerInputComponent* inputComponent,
	PhysicsComponent* physicsComponent,
	ShootingComponent* shootingComponent)
{
	this->inputComponent = inputComponent;
	this->physicsComponent = physicsComponent;
	this->shootingComponent = shootingComponent;

	this->initVariables();
	this->initShip();
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
	this->updateBullets(deltaTime);
}

void Player::render(sf::RenderTarget& target)
{
	this->ship->render(target);

	for (auto& bullet : this->bullets)
		if (bullet)
			target.draw(*bullet);
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

void Player::shoot()
{
	sf::Sprite* bullet = this->shootingComponent->shoot(*this);
	this->bullets.push_back(bullet);
}

void Player::setIdleEngineAnimation()
{
	this->getEngineAnimations()->getSprite()->setTextureRect(this->idleEngineAnimationFrame);
}

void Player::setRunningEngineAnimation()
{
	this->getEngineAnimations()->getSprite()->setTextureRect(this->runningEngineAnimationFrame);
}

void Player::updateBullets(float deltaTime)
{
	for (size_t i = 0; i < this->bullets.size(); ++i)
	{
		if (this->bullets[i])
		{
			if (!this->shootingComponent->updateBullet(*this->bullets[i], deltaTime))
			{
				delete this->bullets[i];
				this->bullets[i] = nullptr;
			}
		}
	}

	this->bullets.erase(std::remove(this->bullets.begin(), this->bullets.end(), nullptr), this->bullets.end());
}

void Player::initVariables()
{
	this->maxVelocityMultiplier = 6.f;
	this->bullets = std::vector<sf::Sprite*>(30); // Making sure we dont resize often.
	this->idleEngineAnimationFrame = sf::IntRect(sf::Vector2i(14, 79), sf::Vector2i(21, 6));
	this->runningEngineAnimationFrame = sf::IntRect(sf::Vector2i(110, 79), sf::Vector2i(21, 9));
	this->health = 10; 
}

void Player::initShip()
{
	this->initShipSprite();
	this->initEngineSprite();
	this->initEngineAnimationSprite();
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
	sprite->setPosition({ 500, 800 });

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
	sprite->setTextureRect(this->idleEngineAnimationFrame);
	sprite->setScale({ 2.3f, 2.3f });
	this->ship->getChildren()[0]->addChild(texture, sprite, { 5.f, 24.f });
}

void Player::initKeyBindings()
{
	this->keyBindings[Constants::MOVE_UP] = sf::Keyboard::Key::W;
	this->keyBindings[Constants::MOVE_DOWN] = sf::Keyboard::Key::S;
	this->keyBindings[Constants::MOVE_LEFT] = sf::Keyboard::Key::A;
	this->keyBindings[Constants::MOVE_RIGHT] = sf::Keyboard::Key::D;
	this->keyBindings[Constants::SHOOT] = sf::Keyboard::Key::Space;
}

TextureNode* Player::getEngine()
{
	return this->ship->getChildren()[0];
}

TextureNode* Player::getEngineAnimations()
{
	return getEngine()->getChildren()[0];
}
