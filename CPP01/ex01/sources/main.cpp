/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:02 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:09:57 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../include/Zombie.hpp"

int	getZombieNb(void)
{
	int		N;
	bool	done = false;

	std::cout << "How many zombie do you want in the horde ?" << std::endl;
	while (!done)
	{
		std::string	line;
		getline(std::cin, line);
		if (std::cin.eof())
			return -1;
		std::istringstream nb(line);
		char	zero = '\0';
		if (!(nb >> N) || (nb >> std::ws && nb.get(zero)) || N > 10000 || N < 1)
			std::cout << "Please enter a number between 1 et 10000 !" << std::endl;
		else
			done = true;
	}
	return N;
}

int main(void)
{
	int	N = getZombieNb();
	if (N == -1)
		return -1 ;

	Zombie *zombHorde = zombieHorde(N, "Cookie");

	for (int i = 0; i < N; i++)
		zombHorde->announce();
	delete [] zombHorde;
}