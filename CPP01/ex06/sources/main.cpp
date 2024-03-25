/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:44:20 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 13:50:38 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "The program takes one argument" << std::endl;	
		return (-1);
	}
	int level;
	Harl Harl;
	
	// std::string s = av[1];
	// std::istringstream f(s);
	// f >> level;

	// if (f.fail() || (level < 1 || level > 4))
	// 	std::cout << "The argument should be a number between 1 and 4" << std::endl;
	level = 0;
	for (int i = 0; i < 4; i++)
	{
		if (av[1] == Harl.level[i])
			level = i + 1;
	}
	Harl.complain(level);
    return 0;
}