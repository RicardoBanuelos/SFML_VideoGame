#include "ObjectPool/ObjectPoolHandler.h"
#include "Bullet/Bullet.h"

ObjectPool<Bullet> ObjectPoolHandler::mBulletPool(30);

Bullet* ObjectPoolHandler::acquireBullet()
{
	return mBulletPool.acquire();
}

void ObjectPoolHandler::releaseBullet(Bullet* bullet)
{
	mBulletPool.release(bullet);
}
