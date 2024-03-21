/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:37:46 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 12:12:12 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie Zomb2 = Zombie(name);
	//comme la fonction ne renvoie rien on ne pourra
	//pas le delete plus tard, on fait donc une allocation
	//sur la pile (la stack)
	Zomb2.announce();
}