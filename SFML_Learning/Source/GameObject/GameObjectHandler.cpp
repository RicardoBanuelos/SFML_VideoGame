#include "GameObject/GameObjectHandler.h"

#include "TextureLoader/TextureLoader.h"
#include "Player/Player.h"

#include "ObjectPool/ObjectPoolHandler.h"
#include "GameMath/GameMath.h"

std::map<ID, std::unordered_set<GameObject*>> GameObjectHandler::mGameObjects;
Player* GameObjectHandler::mPlayer = nullptr;

void GameObjectHandler::update(float deltaTime)
{
	mPlayer->update(deltaTime);

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