#include "Game/Game.h"

#include <iostream>

#include "MousePosition/MousePosition.h"

#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureStrings.h"

#include "GameObject/GameObjectHandler.h"
#include "GameObject/GameObjectBuilder.h"

#include "Player/Player.h"
#include "Zombie/Zombie.h"

#include "ObjectPool/ObjectPoolHandler.h"

Game::Game()
	: mSettings(0, 0, 10),
	mWindow(new sf::RenderWindow(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, mSettings)),
	mCamera(mWindow->getSize().x, mWindow->getSize().y)
{
	mWindow->setVerticalSyncEnabled(true);
	GameObjectHandler::setPlayer(new Player(sf::Vector2f(1920 / 2, 1080 / 2)));

	Player* player = GameObjectHandler::getPlayer();

	Zombie* zombie = GameObjectBuilder::buildZombie(sf::Vector2f(100, 100), player);
	GameObjectHandler::addGameObject(ZOMBIE, zombie);
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

void Game::update(float deltaTime)
{
	pollEvents();
	MousePosition::update(*mWindow);
	GameObjectHandler::update(deltaTime);
	mCamera.follow(GameObjectHandler::getPlayer()->getPosition());
}

void Game::draw()
{
	mWindow->clear(sf::Color::Black);
	GameObjectHandler::draw(*mWindow);
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
				mWindow->close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					mWindow->close();
				}
				break;
			default:
				break;
		}
	}
}