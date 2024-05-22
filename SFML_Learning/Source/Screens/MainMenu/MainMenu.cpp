#include "Screens/MainMenu/MainMenu.h"

#include "Game/Game.h"

#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& window)
	:	mWidth(window.getSize().x),
		mHeight(window.getSize().y)
{
	mFont.loadFromFile("Assets/Fonts/no_continue/gomarice_no_continue.ttf");

	mTitle.setFont(mFont);
	mTitle.setString("Top-Down Zombie Shooter");
	mTitle.setCharacterSize(48);
	mTitle.setFillColor(sf::Color::White);
	
	int width = mTitle.getLocalBounds().width;
	int height = mTitle.getLocalBounds().height;

	mTitle.setPosition(mWidth / 2 - width / 2, 50);

	mPlayButton = new Button(mFont, "Play");
	mExitButton = new Button(mFont, "Exit");

	mPlayButton->setTextSize(48);
	mExitButton->setTextSize(48);

	mPlayButton->setTextColor(sf::Color::White);
	mExitButton->setTextColor(sf::Color::White);

	mPlayButton->setOnHoverColor(sf::Color::Red);
	mExitButton->setOnHoverColor(sf::Color::Red);

	mPlayButton->setSize();
	mExitButton->setSize();

	sf::Vector2f playButtonSize = mPlayButton->getSize();
	sf::Vector2f exitButtonSize = mExitButton->getSize();

	mPlayButton->setPosition(mWidth / 2 - playButtonSize.x / 2, mHeight / 2 - playButtonSize.y / 2);
	mExitButton->setPosition(mWidth / 2 - exitButtonSize.x / 2, (mHeight / 2 - exitButtonSize.y / 2)  + 100);

	mPlayButton->setOnClickFunction([&]() {
		Game::setState(Game::PLAYING);
	});

	mExitButton->setOnClickFunction([&]() {
		Game::setState(Game::EXIT);
	});
}

MainMenu::~MainMenu()
{

}

void MainMenu::update(float deltaTime)
{
	mPlayButton->update(deltaTime);
	mExitButton->update(deltaTime);
}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(mTitle);
	mPlayButton->draw(window);
	mExitButton->draw(window);
}
