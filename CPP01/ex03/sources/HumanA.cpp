/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:43 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 17:14:48 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/***Default Constructor***/
// HumanA::HumanA()
// {
// 	return ;
// }

/***Constructor***/
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	// this->_name = name;
	// this->_Weapon = weapon;
	return ;
}

/***Destructor***/
HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

