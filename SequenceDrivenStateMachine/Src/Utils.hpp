#pragma once

#include <iostream>
class Utils
{
    public:
    Utils() = default;
    Utils(const Utils& src) = delete;
    Utils& operator=(const Utils& src) = delete;
    ~Utils() noexcept = default;

    template<typename Base, typename T>
    static inline bool instanceof(const T*) 
    {
        return std::is_base_of<Base, T>::value;
    }
};//Utils