#pragma once
#include <map>

#include "../Constants.h"
#include "../Player.h"

class PlayerInputComponent
{
public:
	PlayerInputComponent(std::map<std::string, sf::Keyboard::Key> keyBindings);

	void update(Player& player);

private:
	static const float VELOCITY;
	std::map<std::string, sf::Keyboard::Key> keyBindings;
};