/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:54 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/22 10:33:11 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

HumanB::~HumanB()
{
	
}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl; 
}

void	HumanB::setWeapon(Weapon &aWeapon)
{
	this->_weapon = &aWeapon;
} 