#include "Screens/GameOver/GameOver.h"

#include "Screens/MainMenu/MainMenu.h"

#include "Game/Game.h"

#include <iostream>

GameOver::GameOver(sf::RenderWindow& window)
	:	mWidth(window.getSize().x),
		mHeight(window.getSize().y)
{
	mFont.loadFromFile("Assets/Fonts/no_continue/gomarice_no_continue.ttf");

	mTitle.setFont(mFont);
	mTitle.setString("Game Over");
	mTitle.setCharacterSize(64);
	mTitle.setFillColor(sf::Color::Red);

	int width = mTitle.getLocalBounds().width;
	int height = mTitle.getLocalBounds().height;

	mTitle.setPosition(mWidth / 2 - width / 2, mHeight / 2 - height);

	mMessage.setFont(mFont);
	mMessage.setString("Click anywhere to return to the main menu loser.");
	mMessage.setCharacterSize(32);
	mMessage.setFillColor(sf::Color::Red);

	width = mMessage.getLocalBounds().width;
	height = mMessage.getLocalBounds().height;

	mMessage.setPosition(mWidth / 2 - width / 2, (mHeight / 2) - (height / 2) + 100);
}

GameOver::~GameOver()
{

}

void GameOver::update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		Game::setState(Game::MAIN_MENU);
	}
}

void GameOver::draw(sf::RenderWindow& window)
{
	window.draw(mTitle);
	window.draw(mMessage);
}
