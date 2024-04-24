#include <iostream>
#include <vector>
#include <math.h>

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Camera/Camera.h"
#include "TextureLoader/TextureLoader.h"
#include "TextureLoader/TextureStrings.h"


bool isInBounds(int x, int y);
void movePlayer(Player& player);
bool loadTextures(TextureLoader& textureLoader);

std::vector<Bullet> bullets;

int main()
{
#pragma region Window Camera and Textures Setup
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings);

	Camera camera(window.getSize().x, window.getSize().y);

	TextureLoader textureLoader;
	if (!loadTextures(textureLoader))
	{
		std::cout << "Failed loading textures." << std::endl;
		return -1;
	}
#pragma endregion

#pragma region Create Background
	sf::Sprite backgroundSprite(textureLoader.getTexture("background"));
#pragma endregion

#pragma region Create Player
	Player player(window.getSize().x / 2, window.getSize().y / 2, 64, 64, textureLoader.getTexture("player"));
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
					Bullet bullet(player.position().x, player.position().y, 16, 16, mousePosition, textureLoader.getTexture("bullet"));
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
		window.draw(backgroundSprite);

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

bool loadTextures(TextureLoader& textureLoader)
{
	for (int i = 0; i < TextureStrings::SIZE; ++i)
	{
		if (!textureLoader.loadTexture(TextureStrings::names[i], TextureStrings::paths[i])) return false;
	}

	return true;
}