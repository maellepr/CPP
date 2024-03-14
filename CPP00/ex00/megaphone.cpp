/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:26:01 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/13 12:31:37 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string	str = av[i];
			for (int j = 0; str[j]; j++)
			{
				str[j] = std::toupper(str[j]);
			}
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
