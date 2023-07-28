#pragma once

template<typename T>
class CLovelaceSingleton {
public:
    CLovelaceSingleton() = default;
    CLovelaceSingleton(const CLovelaceSingleton&) = delete;
    CLovelaceSingleton& operator=(const CLovelaceSingleton&) = delete;

    static T* Get() {
        static T instance;
        return &instance;
    }
};