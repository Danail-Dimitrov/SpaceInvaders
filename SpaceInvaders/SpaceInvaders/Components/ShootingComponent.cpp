#include "ShootingComponent.h"

ShootingComponent::ShootingComponent()
{
	this->initBulletTexture();
	this->initVariables();
}

ShootingComponent::~ShootingComponent()
{
	delete this->bulletTexture;
}

sf::Sprite* ShootingComponent::shoot(Player& player)
{
	sf::Sprite* bullet = new sf::Sprite(*this->bulletTexture);
	bullet->setPosition(player.getPosition());
	bullet->setScale({ 0.8f, 0.8f });

	return bullet;
}

bool ShootingComponent::updateBullet(sf::Sprite& bullet, float deltaTime)
{
	float newY = bullet.getPosition().y - (this->bulletSpeed * deltaTime);

	if (newY < 0) // If the bullet is out of the 
		return false; // Bullet is no longer in the screen
	
	bullet.setPosition({ bullet.getPosition().x, newY });
	return true; // Bullet is still in the screen
}

void ShootingComponent::initBulletTexture()
{
	this->bulletTexture = new sf::Texture();
	if (!bulletTexture->loadFromFile("Textures/bullet.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
}

void ShootingComponent::initVariables()
{
	this->bulletSpeed = 50.f;
}
