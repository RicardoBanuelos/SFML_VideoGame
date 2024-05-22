#pragma once

#include <SFML/Graphics.hpp>
#include "Camera/Camera.h"
#include "Screens/MainMenu/MainMenu.h"
#include "Screens/GameOver/GameOver.h"

class Game
{
public:
	enum GameState {
		MAIN_MENU,
		PLAYING,
		GAME_OVER,
		PAUSED,
		EXIT,
	};

	static void setState(GameState state);
	static GameState state();

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

	static GameState mGameState;
	MainMenu* mMainMenu;
	GameOver* mGameOver;
 };