#pragma once

#include "../Constants.h"
#include "../Player.h"

class Player;

class PhysicsComponent
{
public:
	void update(Player& player, float deltaTime);
};