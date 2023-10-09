#pragma once
#include <mutex>
#include <memory>

class Singleton 
{
    static std::shared_ptr<Singleton> singletonInstance;
    Singleton() {}
    static std::mutex m_;

  public:

    static std::shared_ptr<Singleton> getSingletonInstance()
    {
        std::lock_guard<std::mutex> lock(m_);
        if(singletonInstance == nullptr)
        {
            singletonInstance = std::make_shared<Singleton>();
        }
        return singletonInstance;
    }
};