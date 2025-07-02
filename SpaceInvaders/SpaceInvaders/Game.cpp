#include "Game.h"

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->enemyTexture;
	for (auto& enemy : enemies) {
		delete enemy;
	}
}

void Game::run()
{
    sf::Clock clock;

    while (this->isRunning()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asMilliseconds();

        pollEvents();

		update(dt);

        render();
    }
}

void Game::pollEvents()
{
	while (const std::optional event = this->window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			this->window->close();
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			// Close the window if the pressed key is escape
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) //Scancode refers to the physical location of the key on the keyboard. For example Z in english and Y in German have the same scancode
				this->window->close();
		}
	}
}

void Game::update(float dt)
{
	this->player->update(dt);
	this->updateEnemies(dt);
}

void Game::spawnEnemies()
{
	if (enemies.size() < maxEnemies && enemySpawnClock.getElapsedTime().asSeconds() >= enemySpawnDelay)
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(50, 950);

		int randomX = dis(gen);
		sf::Vector2f spawnPos(static_cast<float>(randomX), 0.f);

		enemies.push_back(new Enemy(enemyTexture, spawnPos));
		enemySpawnClock.restart();
	}
}

void Game::updateEnemies(float dt)
{
	auto bullets = this->player->getBullets();

	for (auto it = enemies.begin(); it != enemies.end(); )
	{
		Enemy* enemy = *it;
		enemy->update(dt);

		bool isDeleted = false;

		for (auto bulletIt = bullets->begin(); bulletIt != bullets->end(); )
		{
			sf::Sprite* bullet = *bulletIt;

			if (bullet->getGlobalBounds().findIntersection(enemy->getGlobalBounds()))
			{
				if (!enemy->takeDmgage(45)) // Enemy dead. Hardcoding is bad but for the purposes of learning I don't need the game to be perfecr
				{
					delete enemy;
					it = enemies.erase(it);
					isDeleted = true;
				}

				delete bullet;
				bulletIt = bullets->erase(bulletIt);
			}
			else
			{
				++bulletIt;
			}
		}

		if (isDeleted)
			continue;

		if (enemy->getPosition().y > 1000.f)
		{
			delete enemy;
			it = enemies.erase(it);
			this->player->reduceHealth();
		}
		else
		{
			++it;
		}
	}

	this->spawnEnemies();
}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);
	this->renderEnemies();

	this->window->display();
}

void Game::renderEnemies()
{
	for (auto& enemy : enemies) 
		if(enemy)
			enemy->render(*this->window);
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode({ 1000, 1000 }), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(this->fps);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
	this->window = nullptr;
	this->fps = 60;
	this->maxEnemies = 15;
}

void Game::initPlayer()
{
	this->player = new Player(
		new PlayerInputComponent(), 
		new PhysicsComponent(this->window->getSize()),
		new ShootingComponent());
}

void Game::initEnemies()
{
	this->enemyTexture = new sf::Texture();
	if (!this->enemyTexture->loadFromFile("Textures/Enemy.png"))
		std::cout << "ERROR::GAME::INITENEMIES::Could not load enemy texture file." << "\n";

	this->enemySpawnClock.restart();
}

bool Game::isRunning()
{
	return this->window->isOpen() && this->player->isAlive();;
}
