/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:02 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 13:38:13 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main(void)
{
	int	N = 4;
	Zombie *zombHorde = zombieHorde(N, "Cookie");

	for (int i = 0; i < N; i++)
		zombHorde->announce();
	delete [] zombHorde;
}