#include "Game/Game.h"

#include <iostream>

#include "MousePosition/MousePosition.h"

#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureStrings.h"

#include "Zombie/Zombie.h"

#include "ObjectPool/ObjectPoolHandler.h"
#include "GameMath/GameMath.h"

#include <unordered_map>

Game::Game()
	:	mSettings(0, 0, 10),
		mWindow(new sf::RenderWindow(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, mSettings)),
		mCamera(mWindow->getSize().x, mWindow->getSize().y)
{	
	if (!loadAllTextures())
	{
		mWindow->close();
	}

	mWindow->setVerticalSyncEnabled(true);
	mPlayer = new Player(this, sf::Vector2f(1920 / 2, 1080 / 2), TextureLoader::getTexture("Player"));

	mGameObjects[PLAYER].insert(mPlayer);
	mGameObjects[ZOMBIE].insert(new Zombie(sf::Vector2f(300, 300), TextureLoader::getTexture("Zombie"), mPlayer));
	mGameObjects[ZOMBIE].insert(new Zombie(sf::Vector2f(400, 400), TextureLoader::getTexture("Zombie"), mPlayer));
	mGameObjects[ZOMBIE].insert(new Zombie(sf::Vector2f(500, 500), TextureLoader::getTexture("Zombie"), mPlayer));

}

Game::~Game()
{
	delete mWindow;
	delete mPlayer;
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

void Game::create(ID id, GameObject* object)
{
	mGameObjects[id].insert(object);
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

	std::unordered_map<ID, std::vector<GameObject*>> releasedObjects;

	for (auto&& [id, objectSet] : mGameObjects)
	{
		for (auto object : objectSet)
		{
			object->update(deltaTime);

			if (object->id() == ZOMBIE)
			{
				if (GameMath::isColliding(object->hitbox(), mPlayer->hitbox()))
				{
					
				}
			}
			else if (object->id() == BULLET)
			{
				for (auto& zombie : mGameObjects[ZOMBIE])
				{
					if (GameMath::isColliding(object->hitbox(), zombie->hitbox()))
					{
						object->release();
					}
				}
			}

			if (object->isReleased())
			{
				ObjectPoolHandler::releaseBullet(static_cast<Bullet*>(object));
				releasedObjects[id].push_back(object);
			}
		}
	}

	for (auto& [id, objects] : releasedObjects)
	{
		for (auto object : objects)
		{
			mGameObjects[id].erase(object);
		}
	}

	mCamera.follow(mPlayer->getPosition());
}

void Game::draw()
{
	mWindow->clear(sf::Color::Black);

	for (auto&& [id, objectSet] : mGameObjects)
	{
		for (auto object : objectSet)
		{
			object->draw(*mWindow);
		}
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