#ifndef ITER_HPP
#define ITER_HPP

#define BOLD	"\e[1m"
#define DIM		"\e[2m"
#define ITAL	"\e[3m"
#define ULINE	"\e[4m"

#define	YELLOW	"\e[38;2;217;255;0m"
#define	PINK	"\e[38;2;255;0;89m"
#define PURPLE	"\e[38;2;255;0;217m"
#define	GREEN	"\e[38;2;89;255;0m"
#define	RED		"\e[38;2;255;0;0m"
#define BLUE	"\e[38;2;0;233;255m"

#define RESET	"\e[0m"

#include <iostream>
#include <string>

template <typename T>
void	fctIncremente(T & elem)
{
	elem++;
}

template <typename T>
void	fctPrint(T & elem)
{
	std::cout << elem << " ";
}

template <typename T, typename F>
void	iter(T * arrayAddress, int len, void(*fct)(F &)) 
{
	for (int i = 0; i < len; i++)
	{
		fct(arrayAddress[i]);
	}
}

#endif
