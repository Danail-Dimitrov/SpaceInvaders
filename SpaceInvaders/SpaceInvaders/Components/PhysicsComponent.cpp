#include "PhysicsComponent.h"

// In the case of the ship being stuck in one of the cornecrs of the window, when we try to move in the other direction, we will appear stuck. This is because it is "decelerating" and needs some time for the velocity to change its sign.
void PhysicsComponent::update(Player& player, float deltaTime)
{
	float newX = player.getPosition().x + player.getVelocity().x * deltaTime;
	float newY = player.getPosition().y + player.getVelocity().y * deltaTime;
	
	if(newX < 0)
		newX = 0;
	else if(newX + player.getSize().x > windowSize.x)
		newX = windowSize.x - player.getSize().x;

	if (newY < 0)
		newY = 0;
	else if (newY + player.getSize().y > windowSize.y)
		newY = windowSize.y - player.getSize().y;

	player.setPosition(sf::Vector2f(newX, newY));
}
