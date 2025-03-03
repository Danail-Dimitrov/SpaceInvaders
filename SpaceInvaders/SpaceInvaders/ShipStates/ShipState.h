#include "../Player.h"

// I will be making a state machine for the player class
// The main reason for it is that I want to practice it :)
// It will be helpful when making the animations for the player
// Either idling or moving. 
// Shouting has no effect on the animations of the engine
class ShipState
{
public:
	virtual ~ShipState() {}
	virtual ShipState* handleInput(Player& heroine) = 0;
	virtual void update(Player& heroine) = 0;
}