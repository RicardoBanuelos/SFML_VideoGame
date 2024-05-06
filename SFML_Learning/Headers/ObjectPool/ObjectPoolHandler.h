#pragma once

#include "ObjectPool.h"
#include "Bullet/Bullet.h"
#include "Zombie/Zombie.h"

class ObjectPoolHandler {
public:
	ObjectPoolHandler() = delete;

	static Bullet* acquireBullet();
	static void releaseBullet(Bullet* bullet);

	static Zombie* acquireZombie();
	static void releaseZombie(Zombie* zombie);

private:
	static ObjectPool<Bullet> mBulletPool;
	static ObjectPool<Zombie> mZombiePool;
};