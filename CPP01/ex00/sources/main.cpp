/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:23:15 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:36:29 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie	*Zomb1 = newZombie("Alex");
	//allocation avec new (sur le tas heap)
	// Zombie	Zomb3;//Zombie sans nom qui utilise le constructeur par default

	Zomb1->announce();
	randomChump("Alix");
	delete Zomb1;
	
}