#pragma once

class ICollidable {
public:
    virtual void processCollision(ICollidable* other) = 0;
};