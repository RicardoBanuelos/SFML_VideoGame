#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <unordered_set>

#include "GameObject/GameObject.h"
#include "GameObject/GameObjectIDs.h"

class Player;

class GameObjectHandler
{
public:
	GameObjectHandler() = delete;
	static void update(float deltaTime);
	static void draw(sf::RenderWindow& window);
	static std::unordered_set<GameObject*> getByID(ID id);
	static std::map<ID, std::unordered_set<GameObject*>> getAll();
	static void addGameObject(ID id, GameObject* gameObject);
	static void setPlayer(Player* player);
	static Player* getPlayer();

private:
	static void detectCollisions();
	static void detectUnCollisions();
	static void releaseObjects();
	static std::map<ID, std::unordered_set<GameObject*>> mGameObjects;
	static std::map<ID, std::vector<GameObject*>> mReleasedObjects;
	static std::unordered_set<GameObject*> mTriggeredZombies;
	static Player* mPlayer;
};