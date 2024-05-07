#include "GameObject/GameObjectBuilder.h"

#include "Bullet/Bullet.h"
#include "Zombie/Zombie.h"

#include "TextureLoader/TextureLoader.h"

#include "ObjectPool/ObjectPoolHandler.h"

Bullet* GameObjectBuilder::buildBullet(sf::Vector2f position, float angle)
{
	Bullet* bullet = ObjectPoolHandler::instance()->acquireBullet();

	bullet->unRelease();
	bullet->setPosition(position);
	bullet->setRotation(angle);
	bullet->setAngle(angle);

	return bullet;
}