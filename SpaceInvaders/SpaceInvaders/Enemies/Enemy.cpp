#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2f position)
{
	this->initVariables();
	this->initSprite(texture, position);
}

Enemy::~Enemy()
{
	delete this->sprite;
}

void Enemy::update(float deltaTime)
{
	this->sprite->move({ 0.f, this->movementSpeed * deltaTime });
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(*this->sprite);
}

bool Enemy::takeDmgage(int damage)
{
	this->health -= damage;

	return this->health > 0;
}

void Enemy::initSprite(sf::Texture* texture, sf::Vector2f position)
{
	this->sprite = new sf::Sprite(*texture);
	this->sprite->setPosition(position);
	this->sprite->setScale({ 2.5f, 2.5f }); 
}

void Enemy::initVariables()
{
	this->health = 100;
	this->movementSpeed = 0.8f; 
}
