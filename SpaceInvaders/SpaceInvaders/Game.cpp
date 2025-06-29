#include "Game.h"

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
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
}

void Game::render()
{
	this->window->clear();
	this->player->render(*this->window);
	this->window->display();
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
}

void Game::initPlayer()
{
	this->player = new Player(
		new PlayerInputComponent(), 
		new PhysicsComponent(this->window->getSize()),
		new ShootingComponent());
}

bool Game::isRunning()
{
    return this->window->isOpen();
}
