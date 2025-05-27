#include "PhysicsComponent.h"

void PhysicsComponent::update(Player& player, float deltaTime)
{
	player.setPosition(player.getPosition() + player.getVelocity() * deltaTime);
}
