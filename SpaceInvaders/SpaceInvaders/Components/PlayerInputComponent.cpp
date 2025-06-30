#include "PlayerInputComponent.h"

// Instead of making the value so small I can make a cooldown for the keypresses. But I found this soulition to be more simple and suitable for the porpose of this tutorial project.
const float PlayerInputComponent::VELOCITY = 0.04f;

PlayerInputComponent::PlayerInputComponent()
{
	this->initVariables();
}

void PlayerInputComponent::update(Player& player, std::map<std::string, sf::Keyboard::Key>& keyBindings)
{
	bool changed = false;
	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::MOVE_DOWN]))
	{
		player.addYVelocityMult(VELOCITY);
		changed = true;
	}

	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::MOVE_UP]))
	{
		player.addYVelocityMult(-VELOCITY);
		changed = true;
	}

	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::MOVE_LEFT]))
	{
		player.addXVelocityMult(-VELOCITY);
		changed = true;
	}

	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::MOVE_RIGHT]))
	{
		player.addXVelocityMult(VELOCITY);
		changed = true;
	}

	if (!changed) 
	{
		player.resetVelocityMultiplier();

		if (this->wasMovingLastFrame)
		{
			this->wasMovingLastFrame = false;
			player.setIdleEngineAnimation();
		}
	}
	else if (!this->wasMovingLastFrame)
	{
		this->wasMovingLastFrame = true;
		player.setRunningEngineAnimation();
	}

	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::SHOOT]))
		player.shoot();
}

void PlayerInputComponent::initVariables()
{
	this->wasMovingLastFrame = false;
}
