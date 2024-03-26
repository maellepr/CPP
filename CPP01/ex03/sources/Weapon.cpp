/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:21 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:17:41 by mapoirie         ###   ########.fr       */
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

const std::string Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}