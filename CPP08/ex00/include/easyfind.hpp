#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define BOLD	"\e[1m"
#define RESET	"\e[0m"

#include <iostream>
#include <string>

#include <iterator> 
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
int	easyfind(T contener, int nb)
{
	typename T::iterator it;

	it = std::find(contener.begin(), contener.end(), nb);
	if (it != contener.end())
		return nb;
	throw (std::out_of_range("The nb was not find in the contener"));
}

#endif
