#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

#include "Utilities/TextureNode.h"
#include "Constants.h"

#include "Components/PlayerInputComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/ShootingComponent.h"

class PlayerInputComponent;
class PhysicsComponent;

class Player
{
public:
	Player(PlayerInputComponent* inputComponent, 
		PhysicsComponent* physicsComponent,
		ShootingComponent* shootingComponent);

	~Player();

	void update(float deltaTime);
	void render(sf::RenderTarget& target);

	// Velocity management
	void addXVelocityMult(float x);
	void addYVelocityMult(float y);
	void resetVelocityMultiplier() { this->velocity = { 0.f, 0.f }; }

	// Shooting
	void shoot();

	// Setters
	void setPosition(const sf::Vector2f& position) { this->ship->move(position); }

	// Getters
	sf::Vector2f getPosition() const { return this->ship->getPosition(); }
	sf::Vector2f getVelocity() const { return this->velocity; }
	sf::Vector2f getSize() const { return this->ship->getSize(); }

private:
	// Sprites
	TextureNode* ship;
	sf::IntRect currentEngineFrame;

	// Key bindings
	std::map<std::string, sf::Keyboard::Key> keyBindings;

	// Movment
	sf::Vector2f velocity;
	float maxVelocityMultiplier;

	// Bullets
	std::vector<sf::Sprite*> bullets;

	// Components
	PlayerInputComponent* inputComponent;
	PhysicsComponent* physicsComponent;
	ShootingComponent* shootingComponent;

	// Inits
	void initVariables();
	void initShip();
	void initShipSprite();
	void initEngineSprite();
	void initEngineAnimationSprite();
	void initKeyBindings();

	// Getters
	TextureNode* getEngine();
	TextureNode* getEngineAnimations();
};