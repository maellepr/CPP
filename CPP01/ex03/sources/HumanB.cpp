/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:54 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 16:59:43 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/***Default Constructor***/
HumanB::HumanB()
{
	return ;
}

/***Constructor***/
HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

/***Destructor***/
HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;	
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}