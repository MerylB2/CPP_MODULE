#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& cnt, int val)
{
    typename T::iterator it = std::find(cnt.begin(), cnt.end(), val);
    if (it == cnt.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& cnt, int val)
{
    typename T::const_iterator it = std::find(cnt.begin(), cnt.end(), val);
    if (it == cnt.end())
        throw std::runtime_error("Value not found in container");
    return it;
}


#endif