#pragma once

#include <SFML/Graphics.hpp>
#include <Player/Player.h>

class Game 
{
public:
	Game();
	~Game();

	void run();

private:
	void pollEvents();
	void update();
	void draw();

	sf::ContextSettings mSettings;
	sf::RenderWindow* mWindow;
 };