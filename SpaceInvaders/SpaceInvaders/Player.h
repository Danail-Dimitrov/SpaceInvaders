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
class ShootingComponent;

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

	// Mutators
	void setPosition(const sf::Vector2f& position) { this->ship->move(position); }
	void reduceHealth(int amount = 1) { this->health -= amount; }

	// Animation
	void setIdleEngineAnimation();
	void setRunningEngineAnimation();

	// Accessors
	sf::Vector2f getPosition() const { return this->ship->getPosition(); }
	sf::Vector2f getVelocity() const { return this->velocity; }
	sf::Vector2f getSize() const { return this->ship->getSize(); }
	std::vector<sf::Sprite*>* getBullets() { return &this->bullets; }
	bool isAlive() const { return this->health > 0; }

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

	// Engine Animation
	sf::IntRect idleEngineAnimationFrame;
	sf::IntRect runningEngineAnimationFrame;

	// Variables
	int health;

	// Updates
	void updateBullets(float deltaTime);

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