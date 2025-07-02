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
	if (shotClock.getElapsedTime().asSeconds() < shotDelay)
		return nullptr;

	shotClock.restart();

	sf::Sprite* bullet = new sf::Sprite(*this->bulletTexture);
	bullet->setPosition(player.getPosition());
	bullet->setScale({ 0.8f, 0.8f });

	return bullet;
}

bool ShootingComponent::updateBullet(sf::Sprite& bullet, float deltaTime)
{
	float newY = bullet.getPosition().y - (this->bulletSpeed * deltaTime);

	// Seems like a bad idea to have that logic here. It feels like I should move it to the game class. I will leave it here for now sinse this is just for learning purposes and I don't need it to be perfect.
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
	this->bulletSpeed = 1.5f;
	this->shotDelay = 0.2f;
}
