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
	mHitBox.setPosition(getPosition());
	mHitBox.setRotation(getRotation());
}

void GameObject::draw(sf::RenderWindow& window)
{
#ifdef TESTING
	window.draw(mHitBox);
#endif

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

ID GameObject::id()
{
	return mID;
}

sf::FloatRect GameObject::hitbox()
{
	return mHitBox.getGlobalBounds();
}

void GameObject::initHitBox()
{
#ifdef TESTING
	mHitBox.setFillColor(sf::Color::Transparent);
	mHitBox.setOutlineColor(sf::Color::Red);
	mHitBox.setOutlineThickness(1.0f);
#endif

	mHitBox.setPosition(getPosition());
	sf::Vector2i textureSize = getTextureRect().getSize();
	mHitBox.setSize(static_cast<sf::Vector2f>(textureSize));
	mHitBox.setScale(0.60f, 0.60f);
}

void GameObject::alignCenter()
{
	sf::Vector2i textureSize = getTextureRect().getSize();

	setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
	mHitBox.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
}