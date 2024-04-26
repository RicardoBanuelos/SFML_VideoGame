#pragma once

enum ID;
class GameObject;

class IGameObjectCreator {
public:
	virtual void create(ID id, GameObject* object) = 0;
};