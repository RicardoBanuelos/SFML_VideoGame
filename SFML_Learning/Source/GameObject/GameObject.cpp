#include "GameObject/GameObject.h"

GameObject::GameObject(float x, float y, float width, float height, sf::Texture& texture)
	:	mTexture(texture),
		mSprite(texture)
{
	mShape.setPosition(x, y);
	mShape.setSize(sf::Vector2f(width, height));
	mSprite.setPosition(x, y);
}

GameObject::~GameObject()
{

}

void GameObject::update(float deltaTime)
{

}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
}

sf::Vector2f GameObject::position()
{
	return mShape.getPosition();
}