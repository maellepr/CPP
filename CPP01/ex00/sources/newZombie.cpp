/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:37:49 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 10:36:03 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*Zomb = new Zombie(name);
	//allocation sur le tas (heap) car on envoie un
	//pointeur et on devra le delete plus tard
	return (Zomb);
}