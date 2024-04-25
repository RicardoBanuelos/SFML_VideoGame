#include "Game/Game.h"

Game::Game()
	:	mSettings(0, 0, 10),
		mWindow(new sf::RenderWindow(sf::VideoMode(1280,720), "RPG Game", sf::Style::Default, mSettings))
{
	mWindow->setFramerateLimit(500);
}

Game::~Game()
{
	delete mWindow;
}

void Game::run()
{
	while (mWindow->isOpen())
	{
		update();
		draw();
	}
}

void Game::update()
{
	pollEvents();
}

void Game::draw()
{
	mWindow->clear(sf::Color::Black);
	mWindow->display();
}

void Game::pollEvents()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				this->mWindow->close();
				break;
		}
	}
}