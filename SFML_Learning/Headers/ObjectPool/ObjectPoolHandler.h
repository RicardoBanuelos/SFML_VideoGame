#pragma once

#include "ObjectPool.h"
class Bullet;

class ObjectPoolHandler {
public:
	ObjectPoolHandler() = delete;
	static Bullet* acquireBullet();
	static void releaseBullet(Bullet* bullet);

private:
	static ObjectPool<Bullet> mBulletPool;
};