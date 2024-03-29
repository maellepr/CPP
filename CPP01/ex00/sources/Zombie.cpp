/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:03:54 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 13:44:16 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie with no name has been created !" << std::endl;	
	return ;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "A zombie named " << name << " has been created !" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed !" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
