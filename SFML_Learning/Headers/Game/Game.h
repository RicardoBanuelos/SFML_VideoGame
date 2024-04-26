#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject/GameObject.h"
#include "GameObject/GameObjectIDs.h"
#include "GameObject/IGameObjectCreator.h"
#include "Player/Player.h"
#include "Camera/Camera.h"

#include<map>
#include<unordered_set>

class Game : public IGameObjectCreator
{
public:
	Game();
	~Game();

	void run();

protected:
	void create(ID id, GameObject* object) override;

private:
	bool loadAllTextures();

	void update(float deltaTime);
	void draw();

	void pollEvents();

	sf::ContextSettings mSettings;
	sf::RenderWindow* mWindow;

	std::map<ID, std::unordered_set<GameObject*>> mGameObjects;
	Player* mPlayer;

	Camera mCamera;
 };