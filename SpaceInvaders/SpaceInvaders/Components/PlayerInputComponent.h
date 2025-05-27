#pragma once
#include <map>

#include "../Constants.h"
#include "../Player.h"

class Player;

class PlayerInputComponent
{
public:
	void update(Player& player, std::map<std::string, sf::Keyboard::Key>& keyBindings);

private:
	static const float VELOCITY;
};