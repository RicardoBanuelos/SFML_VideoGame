#include "ObjectPool/ObjectPoolHandler.h"

ObjectPoolHandler* ObjectPoolHandler::mInstance = nullptr;

ObjectPoolHandler::ObjectPoolHandler()
	:	mBulletPool(50),
		mZombiePool(50)
{}

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