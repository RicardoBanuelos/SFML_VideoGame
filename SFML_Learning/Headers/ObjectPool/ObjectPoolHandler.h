#pragma once

#include "ObjectPool.h"
#include "Bullet/Bullet.h"
#include "Zombie/Zombie.h"

class ObjectPoolHandler {
public:
	static ObjectPoolHandler* instance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new ObjectPoolHandler();
		}

		return mInstance;
	}

	~ObjectPoolHandler() {}

	Bullet* acquireBullet();
	void releaseBullet(Bullet* bullet);

	Zombie* acquireZombie();
	void releaseZombie(Zombie* zombie);

	static ObjectPoolHandler* mInstance;

private:
	ObjectPoolHandler();
	ObjectPool<Bullet> mBulletPool;
	ObjectPool<Zombie> mZombiePool;
};