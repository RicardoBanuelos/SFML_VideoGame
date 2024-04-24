#include "GameObject/GameObject.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, sf::Texture& texture)
	:	mPosition(position),
		mSize(size),
		mTexture(texture),
		mSprite(texture)
{
	mSprite.setPosition(mPosition);
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
	return mPosition;
}