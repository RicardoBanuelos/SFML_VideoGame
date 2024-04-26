#pragma once

#include "Character/Character.h"

#include "Bullet/Bullet.h"

#include <vector>

class Player : public Character {
public:
	Player();
	Player(float x, float y, float width, float height, sf::Texture& texture);
	virtual ~Player();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(sf::Vector2f direction) override;
private:
	void checkKeyInput(float deltaTime);
	void rotate();
	void shoot(float deltaTime);

	sf::RectangleShape mBulletStartPoint;
	std::vector<Bullet> mBullets;
};