#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <set>
#include <map>

template < typename T>

typename T::iterator easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if(it != container.end())
        return it;
    else
        throw std::runtime_error("Value not found in the Container");
}
#endif