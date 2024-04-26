#include "Game/Game.h"

#include <iostream>

#include "MousePosition/MousePosition.h"

#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureStrings.h"

Game::Game()
	:	mSettings(0, 0, 10),
		mWindow(new sf::RenderWindow(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, mSettings)),
		mCamera(mWindow->getSize().x, mWindow->getSize().y)
{	
	if (!loadAllTextures())
	{
		mWindow->close();
	}

	mPlayer = Player(sf::Vector2f(1920 / 2, 1080 / 2), TextureLoader::getTexture("Player"));
	mZombie = Zombie(sf::Vector2f(300, 300), TextureLoader::getTexture("Zombie"));
}

Game::~Game()
{
	delete mWindow;
}

void Game::run()
{
	sf::Clock gameClock;

	while (mWindow->isOpen())
	{
		float deltaTime = gameClock.restart().asSeconds();

		update(deltaTime);
		draw();

		mWindow->setView(mCamera.getView());
	}
}

bool Game::loadAllTextures()
{
	for (auto& [name, path] : TextureStrings::texturePaths)
	{
		if (!TextureLoader::loadTexture(name, path))
		{
			std::cout << "Failed loading textures." << std::endl;
			return false;
		}
	}

	std::cout << "Succesfully loaded all textures." << std::endl;
	return true;
}

void Game::update(float deltaTime)
{
	pollEvents();
	MousePosition::update(*mWindow);
	mPlayer.update(deltaTime);
	mZombie.update(deltaTime);

	mCamera.follow(mPlayer.getPosition());
}

void Game::draw()
{
	mWindow->clear(sf::Color::Black);

	mPlayer.draw(*mWindow);
	mZombie.draw(*mWindow);

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
			default:
				break;
		}
	}
}