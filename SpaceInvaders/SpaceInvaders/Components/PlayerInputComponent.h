#pragma once
#include <map>

#include "../Constants.h"
#include "../Player.h"

class Player;

class PlayerInputComponent
{
public:
	PlayerInputComponent();

	void update(Player& player, std::map<std::string, sf::Keyboard::Key>& keyBindings);

private:
	bool wasMovingLastFrame;

	static const float VELOCITY;

	void initVariables();
};