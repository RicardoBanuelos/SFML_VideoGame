#pragma once

#include <SFML/Graphics.hpp>
#include "Camera/Camera.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void update(float deltaTime);
	void draw();

	void pollEvents();

	sf::ContextSettings mSettings;
	sf::RenderWindow* mWindow;

	Camera mCamera;
 };