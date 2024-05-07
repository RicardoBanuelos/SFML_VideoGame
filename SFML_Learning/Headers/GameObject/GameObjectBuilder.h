#pragma once

class Bullet;
class Zombie;
class Player;

#include <SFML/Graphics.hpp>

class GameObjectBuilder {
public:
	GameObjectBuilder() = delete;
	static Bullet* buildBullet(sf::Vector2f position, float angle);
	static Zombie* buildZombie(sf::Vector2f position, Player* player);
};