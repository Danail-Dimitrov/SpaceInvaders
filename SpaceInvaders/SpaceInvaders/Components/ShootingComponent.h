#pragma once
#include <SFML/System/Clock.hpp>

#include "../Player.h"

class Player;

class ShootingComponent
{
public:
	ShootingComponent();
	~ShootingComponent();

	sf::Sprite* shoot(Player& player);

	/// <summary>
	/// Updates a single bullet.
	/// </summary>
	/// <param name="bullet">The bullet</param>
	/// <param name="deltaTime">Delta time</param>
	/// <returns>Returns true if the bullet is still in the screen. If not-false</returns>
	bool updateBullet(sf::Sprite& bullet, float deltaTime);

private:
	sf::Texture* bulletTexture;
	float bulletSpeed;
	sf::Clock shotClock;
	float shotDelay;

	void initBulletTexture();
	void initVariables();
};