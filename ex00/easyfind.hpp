#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>

typename T::iterator easyfind(T& conteiner, int value)
{
    typename T::iterator it;

    it = std::find(conteiner.begin(), conteiner.end(), value);

    if(it == conteiner.end())
        throw(std::runtime_error("Value not found"));
    return(it);
}


#endif
