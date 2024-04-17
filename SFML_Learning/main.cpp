#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
#pragma region Window Setup
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(600, 600), "RPG Game", sf::Style::Default, settings);
#pragma endregion
	
#pragma region Load
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		return -1;
	}

	int xIndex = 6;
	int yIndex = 2;
	sf::Sprite playerSprite(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
#pragma endregion

#pragma region Main Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed())
			{
				window.close();
			}
		}
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

		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	}
#pragma endregion

	return 0;
}