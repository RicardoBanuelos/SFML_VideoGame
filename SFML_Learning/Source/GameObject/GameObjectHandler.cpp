#include "GameObject/GameObjectHandler.h"

#include "TextureLoader/TextureLoader.h"
#include "Player/Player.h"

#include "ObjectPool/ObjectPoolHandler.h"
#include "GameMath/GameMath.h"

#include "Zombie/Zombie.h"

std::map<ID, std::unordered_set<GameObject*>> GameObjectHandler::mGameObjects;
std::map<ID, std::vector<GameObject*>> GameObjectHandler::mReleasedObjects;
Player* GameObjectHandler::mPlayer = nullptr;

void GameObjectHandler::update(float deltaTime)
{
	mPlayer->update(deltaTime);

	for (auto&& [id, objectSet] : mGameObjects)
	{
		for (auto& object : objectSet)
		{
			object->update(deltaTime);
		}
	}

	detectCollisions();
	releaseObjects();
}

void GameObjectHandler::draw(sf::RenderWindow& window)
{
	mPlayer->draw(window);

	for (auto&& [id, objectSet] : mGameObjects)
	{
		for (auto object : objectSet)
		{
			object->draw(window);
		}
	}
}

std::unordered_set<GameObject*> GameObjectHandler::getByID(ID id)
{
	return mGameObjects[id];
}

std::map<ID, std::unordered_set<GameObject*>> GameObjectHandler::getAll()
{
	return mGameObjects;
}

void GameObjectHandler::addGameObject(ID id, GameObject* gameObject)
{
	mGameObjects[id].insert(gameObject);
}

void GameObjectHandler::setPlayer(Player* player)
{
	mPlayer = player;
}

Player* GameObjectHandler::getPlayer()
{
	return mPlayer;
}

void GameObjectHandler::detectCollisions()
{
	for (auto&& [id, objectSet] : mGameObjects)
	{
		for (auto object : objectSet)
		{			
			if (object->id() == BULLET)
			{
				for (auto& zombie : mGameObjects[ZOMBIE])
				{
					if (GameMath::isColliding(object->hitbox(), zombie->hitbox()))
					{
						object->processCollision(zombie);
					}
				}
			}

			if (object->isReleased())
			{
				ID id = object->id();

				if (id == BULLET)
				{
					ObjectPoolHandler::instance()->releaseBullet(dynamic_cast<Bullet*>(object));
				}
				else if (id == ZOMBIE)
				{
					ObjectPoolHandler::instance()->releaseZombie(dynamic_cast<Zombie*>(object));
				}
					

				mReleasedObjects[id].push_back(object);
			}
		}
	}
}

void GameObjectHandler::releaseObjects()
{
	for (auto& [id, objects] : mReleasedObjects)
	{
		for (auto object : objects)
		{
			mGameObjects[id].erase(object);
		}
	}

	mReleasedObjects.clear();
}