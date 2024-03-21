/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:58 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 13:44:25 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie with no name has been created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "A zombie named " << name << " has been created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "A zombie has been deleted !" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	std::cout << "This zombie name is " << name << std::endl;
}