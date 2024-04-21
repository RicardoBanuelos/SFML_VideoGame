#include <iostream>
#include <vector>
#include <math.h>

#include "Player/Player.h"

bool isInBounds(int x, int y);
void normalize(sf::Vector2f& vector);
void movePlayer(Player& player);

int main()
{
	const float BULLET_SPEED = 0.5f;
#pragma region Window Setup
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings);
#pragma endregion
	
#pragma region Init Bullet
	std::vector<sf::RectangleShape> bulletShapes;
	std::vector<sf::Vector2f> bulletDirections;
#pragma endregion

#pragma region Load Player
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		return -1;
	}

	sf::Vector2f playerPosition(window.getSize().x / 2, window.getSize().y / 2);
	sf::Vector2f playerSize(64, 64);
	Player player(playerPosition, playerSize, playerTexture);
#pragma endregion

#pragma region Main Loop
	while (window.isOpen())
	{
#pragma region Events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed())
			{
				window.close();
			}

			/*if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

					if (!isInBounds(mousePosition.x, mousePosition.y)) continue;

					sf::Vector2f playerPosition = playerSprite.getPosition();
					
					sf::RectangleShape bulletShape(sf::Vector2f(10, 10));
					bulletShape.setPosition(playerPosition.x, playerPosition.y);
					bulletShape.setFillColor(sf::Color::White);
					bulletShapes.push_back(bulletShape);

					sf::Vector2f bulletDirection = mousePosition - playerPosition;
					normalize(bulletDirection);
					bulletDirections.push_back(bulletDirection);
				}
			}*/
		}
#pragma endregion

#pragma region Movement
		movePlayer(player);
#pragma endregion

#pragma region Bullet Movement
		for (int i = 0; i < bulletShapes.size(); ++i)
		{
			bulletShapes[i].move(bulletDirections[i] * BULLET_SPEED);
		}
#pragma endregion

#pragma region Window Bottom Methods
		window.clear(sf::Color::Black);
		player.draw(window);
		
		for (int i = 0; i < bulletShapes.size(); ++i)
		{
			window.draw(bulletShapes[i]);
		}

		window.display();
#pragma endregion
	}
#pragma endregion

	return 0;
}

bool isInBounds(int x, int y)
{
	return x >= 0 && x < 1280 && y >= 0 && y < 720;
}

void normalize(sf::Vector2f& vector)
{
	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

	vector.x /= magnitude;
	vector.y /= magnitude;
}

void movePlayer(Player& player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.move(sf::Vector2f(0, -0.2));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.move(sf::Vector2f(-0.2, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.move(sf::Vector2f(0, 0.2));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.move(sf::Vector2f(0.2, 0));
	}
}