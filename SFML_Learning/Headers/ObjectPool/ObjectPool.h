#pragma once

#include <stack>
#include <memory>
#include <iostream>

template <typename T>
class ObjectPool
{
public:
    ObjectPool(size_t initialSize)
    {
        for (size_t i = 0; i < initialSize; ++i)
        {
            pool.push(new T());
        }
    }

    T* acquire()
    {
        if (pool.empty())
        {
            // If the pool is empty, create a new object
            std::cout << "Warning allocating object...\n\r";
            return new T();
        }
        else
        {
            // Otherwise, take an object from the pool
            auto object = pool.top();
            pool.pop();
            return object;
        }
    }

    void release(T* object)
    {
        // Return the object to the pool
        pool.push(object);
    }

private:
    std::stack<T*> pool;
};