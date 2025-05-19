#include "PlayerInputComponent.h"

const float PlayerInputComponent::VELOCITY = 0.5f;

void PlayerInputComponent::update(Player& player)
{
	bool changed = false;
	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::MOVE_UP]))
	{
		player.addYVelocityMult(VELOCITY);
		changed = true;
	}

	if (sf::Keyboard::isKeyPressed(keyBindings[Constants::MOVE_DOWN]))
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
		player.resetVelocityMultiplier();
}

PlayerInputComponent::PlayerInputComponent(std::map<std::string, sf::Keyboard::Key> keyBindings)
{
	this->keyBindings = keyBindings;
}
