#pragma once

#include <SFML/Graphics.hpp>

#include "Player/Player.h"
#include "Zombie/Zombie.h"

#include "Camera/Camera.h"

class Game 
{
public:
	Game();
	~Game();

	void run();

private:
	bool loadAllTextures();

	void update(float deltaTime);
	void draw();

	void pollEvents();

	sf::ContextSettings mSettings;
	sf::RenderWindow* mWindow;

	Player mPlayer;
	Zombie mZombie;

	Camera mCamera;
 };