#include "Game/Game.h"

#include <iostream>

#include "MousePosition/MousePosition.h"

#include "GameObject/GameObjectHandler.h"
#include "GameObject/GameObjectBuilder.h"

#include "Player/Player.h"
#include "Zombie/Zombie.h"

#include "ObjectPool/ObjectPoolHandler.h"

Game::GameState Game::mGameState = Game::GameState::MAIN_MENU;

Game::Game()
	:	mSettings(0, 0, 10),
		mWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, mSettings)),
		mCamera(mWindow->getSize().x, mWindow->getSize().y),
		mMainMenu(new MainMenu(*mWindow)),
		mGameOver(new GameOver(*mWindow))
{
	mWindow->setVerticalSyncEnabled(true);
	GameObjectHandler::setPlayer(new Player(sf::Vector2f(1920 / 2, 1080 / 2)));

	Player* player = GameObjectHandler::getPlayer();

	Zombie* zombie = GameObjectBuilder::buildZombie(sf::Vector2f(100, 100), player);
	GameObjectHandler::addGameObject(ZOMBIE, zombie);

	zombie = GameObjectBuilder::buildZombie(sf::Vector2f(200, 200), player);
	GameObjectHandler::addGameObject(ZOMBIE, zombie);

	zombie = GameObjectBuilder::buildZombie(sf::Vector2f(300, 300), player);
	GameObjectHandler::addGameObject(ZOMBIE, zombie);

	zombie = GameObjectBuilder::buildZombie(sf::Vector2f(400, 400), player);
	GameObjectHandler::addGameObject(ZOMBIE, zombie);

	zombie = GameObjectBuilder::buildZombie(sf::Vector2f(500, 500), player);
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
	}
}

void Game::update(float deltaTime)
{
	pollEvents();
	MousePosition::update(*mWindow);

	switch (mGameState)
	{
		case MAIN_MENU:	
			mMainMenu->update(deltaTime);
			break;
		case PLAYING:
			GameObjectHandler::update(deltaTime);
			mCamera.follow(GameObjectHandler::getPlayer()->getPosition());
			mWindow->setView(mCamera.getView());
			break;
		case GAME_OVER:
			mGameOver->update(deltaTime);
			break;
		case EXIT:
			mWindow->close();
			break;
		default:
			break;
	}
}

void Game::draw()
{
	mWindow->clear(sf::Color::Black);

	switch (mGameState)
	{
		case MAIN_MENU:
			mMainMenu->draw(*mWindow);
			break;
		case PLAYING:
			GameObjectHandler::draw(*mWindow);
			break;
		case GAME_OVER:
			mGameOver->draw(*mWindow);
			break;
		default:
			break;
	}

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

void Game::setState(GameState state)
{
	mGameState = state;
}

Game::GameState Game::state()
{
	return mGameState;
}