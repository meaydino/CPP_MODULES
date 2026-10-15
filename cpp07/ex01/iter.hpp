#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>


template<typename T, typename Func>
void iter(T *array, size_t len, Func func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template<typename T, typename Func>
void iter(const T *array, size_t len, Func func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}


#endif
