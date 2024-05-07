#pragma once

class Bullet;
class Zombie;

#include <SFML/Graphics.hpp>

class GameObjectBuilder {
public:
	GameObjectBuilder() = delete;
	static Bullet* buildBullet(sf::Vector2f position, float angle);
};