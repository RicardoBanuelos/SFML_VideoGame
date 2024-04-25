#pragma once

#include "GameObject/GameObject.h"

class Character : public GameObject {
public:
	Character(float x, float y, float width, float height, sf::Texture& texture);
	virtual ~Character();

	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(sf::Vector2f direction);

private:
};