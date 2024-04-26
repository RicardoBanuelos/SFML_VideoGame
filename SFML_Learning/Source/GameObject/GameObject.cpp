#include "GameObject/GameObject.h"

GameObject::GameObject()
	:	mID(UNDEFINED),
		mHitBox(),
		mSpeed(0.0f),
		mReleased(false)
{
}

GameObject::GameObject(sf::Vector2f position, const sf::Texture& texture)
	:	GameObject()
{
	mReleased = false;

	setTexture(texture);
	setPosition(position);

	initHitBox();
	alignCenter();
}

GameObject::~GameObject()
{

}

void GameObject::update(float deltaTime)
{
	
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

bool GameObject::isReleased()
{
	return mReleased;
}

void GameObject::release()
{
	mReleased = true;
}
void GameObject::unRelease()
{
	mReleased = false;
}

void GameObject::initHitBox()
{
	mHitBox.setPosition(getPosition());
	sf::Vector2i textureSize = getTextureRect().getSize();
	mHitBox.setSize(static_cast<sf::Vector2f>(textureSize));
}

void GameObject::alignCenter()
{
	sf::Vector2i textureSize = getTextureRect().getSize();

	setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
	mHitBox.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
}