/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:37:46 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:07:48 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie Zomb2 = Zombie(name);
	//comme la fonction ne renvoie rien on ne pourra pas 
	//le delete plus tard, on fait donc une allocation sur la pile/stack

	Zomb2.announce();
}