/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:20:17 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 13:37:50 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombHorde[i].setName(name);
	// zombHorde[0].setName("Gregoire");
	// zombHorde[1].setName("Gaga");
	// zombHorde[2].setName(name);
	// zombHorde[3].setName("Dede");
	return (zombHorde);
}