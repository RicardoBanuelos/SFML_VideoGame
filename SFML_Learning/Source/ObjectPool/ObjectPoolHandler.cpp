#include "ObjectPool/ObjectPoolHandler.h"

ObjectPool<Bullet> ObjectPoolHandler::mBulletPool(30);
ObjectPool<Zombie> ObjectPoolHandler::mZombiePool(30);

Bullet* ObjectPoolHandler::acquireBullet()
{
	return mBulletPool.acquire();
}

void ObjectPoolHandler::releaseBullet(Bullet* bullet)
{
	mBulletPool.release(bullet);
}

Zombie* ObjectPoolHandler::acquireZombie()
{
	return mZombiePool.acquire();
}

void ObjectPoolHandler::releaseZombie(Zombie* zombie)
{
	mZombiePool.release(zombie);
}