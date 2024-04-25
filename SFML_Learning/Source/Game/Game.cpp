#include "Game/Game.h"

#include <iostream>

#include "MousePosition/MousePosition.h"

#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureStrings.h"

Game::Game()
	:	mSettings(0, 0, 10),
		mWindow(new sf::RenderWindow(sf::VideoMode(1920,1080), "RPG Game", sf::Style::Default, mSettings))
{	
	if (!loadAllTextures())
	{
		mWindow->close();
	}

	mPlayer = Player(1280 / 2, 720 / 2, 253, 216, TextureLoader::getTexture("Player"));
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
}

void Game::draw()
{
	mWindow->clear(sf::Color::Black);

	mPlayer.draw(*mWindow);

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

			/*case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					sf::Vector2i mousePixelCoords = sf::Mouse::getPosition(*mWindow);
					sf::Vector2f mouseWorldCoords = mWindow->mapPixelToCoords(mousePixelCoords);

					std::cout << mouseWorldCoords.x << " | " << mouseWorldCoords.y << std::endl;
				}
				break;*/
			default:
				break;
		}
	}
}