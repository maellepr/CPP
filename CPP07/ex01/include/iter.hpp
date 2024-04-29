#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	fctIncremente(T & elem)
{
	elem++;
}

template <typename T>
void	iter(T * arrayAddress, int len, void(*fct)(T & element)) 
{
	for (int i = 0; i < len; i++)
	{
		T &elem = arrayAddress[i];
		fct(elem);
	}
}

#endif
