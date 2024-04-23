#include <iostream>
#include <vector>
#include <math.h>

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Camera/Camera.h"

bool isInBounds(int x, int y);
void normalize(sf::Vector2f& vector);
void movePlayer(Player& player);

std::vector<Bullet> bullets;

int main()
{
#pragma region Window Setup
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings);

	Camera camera(window.getSize().x, window.getSize().y);
#pragma endregion

	
#pragma region Create Player
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

#pragma region Bullet Texture
	sf::Texture bulletsTexture;
	if (!bulletsTexture.loadFromFile("assets/bullets.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		return -1;
	}
#pragma endregion

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
					Bullet bullet(player.position(), sf::Vector2f(16, 16), mousePosition, bulletsTexture);
					bullets.push_back(bullet);
				}
			}
		}
#pragma endregion

#pragma region Update
		movePlayer(player);

		player.update(0);
		camera.setCenter(player.position().x, player.position().y);
		window.setView(camera.getView());
		for (Bullet& bullet : bullets)
		{
			bullet.update(0);
		}
#pragma endregion

#pragma region Draw
		window.clear(sf::Color::Black);

		player.draw(window);
		for (Bullet& bullet : bullets)
		{
			bullet.draw(window);
		}

		window.display();
#pragma endregion
	}

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