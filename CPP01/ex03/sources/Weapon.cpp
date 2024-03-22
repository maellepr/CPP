/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:21 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/22 10:06:36 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string wType)
{
	this->_type = wType;
}

Weapon::~Weapon()
{
	
}

std::string Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}