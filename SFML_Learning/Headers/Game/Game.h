#pragma once

#include <SFML/Graphics.hpp>

#include "Player/Player.h"

class Game 
{
public:
	Game();
	~Game();

	void run();

private:
	bool loadAllTextures();

	void update();
	void draw();

	void pollEvents();

	sf::ContextSettings mSettings;
	sf::RenderWindow* mWindow;

	Player mPlayer;
 };