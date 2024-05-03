#pragma once

#include "GameObjectIDs.h"

#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite {
public:
	GameObject();
	GameObject(sf::Vector2f position, const sf::Texture& texture);
	virtual ~GameObject();

	virtual void init() = 0;
	virtual void update(float deltaTime);
	virtual void draw(sf::RenderWindow& window);

	bool isReleased();
	void release();
	void unRelease();

	ID id();

	sf::FloatRect hitbox();

protected:
	ID mID;
	sf::RectangleShape mHitBox;
	float mSpeed;
	bool mReleased;
	void initHitBox();
	void alignCenter();
};