#include <iostream>
#include <vector>
#include <math.h>

#include <SFML/Graphics.hpp>

bool isInBounds(int x, int y);
void normalize(sf::Vector2f& vector);

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

	sf::Sprite playerSprite(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(64 * 6, 64 * 2, 64, 64));
	playerSprite.setPosition(sf::Vector2f((window.getSize().x / 2), (window.getSize().y / 2)));
#pragma endregion

#pragma region Load Skeleton
	sf::Texture skeletonTexture;
	if (!skeletonTexture.loadFromFile("assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Failed to load skeleton spritesheet!" << std::endl;
		return -1;
	}

	sf::Sprite skeletonSprite(skeletonTexture);
	skeletonSprite.setTextureRect(sf::IntRect(64 * 4, 64 * 2, 64, 64));
	skeletonSprite.scale(sf::Vector2f(3, 3));
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

			if (event.type == sf::Event::MouseButtonPressed)
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
			}
		}
#pragma endregion

#pragma region Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			playerSprite.move(sf::Vector2f(0, -0.2));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerSprite.move(sf::Vector2f(-0.2, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			playerSprite.move(sf::Vector2f(0, 0.2));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerSprite.move(sf::Vector2f(0.2, 0));
		}
#pragma endregion

#pragma region Bullet Movement
		for (int i = 0; i < bulletShapes.size(); ++i)
		{
			bulletShapes[i].move(bulletDirections[i] * BULLET_SPEED);
		}
#pragma endregion

#pragma region Window Bottom Methods
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(skeletonSprite);
		
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