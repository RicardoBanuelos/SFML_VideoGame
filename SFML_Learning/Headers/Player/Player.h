#pragma once

#include "Character/Character.h"

class Player : public Character {
public:
	Player(float x, float y, float width, float height, sf::Texture& texture);
	virtual ~Player();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(sf::Vector2f direction) override;
private:

};