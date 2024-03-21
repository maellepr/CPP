/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:21 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 17:12:46 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/***Default Constructor***/
// Weapon::Weapon()
// {
// 	return ;	
// }

/***Constructor***/
Weapon::Weapon(std::string type): _type(type)
{
	// setType(type);
	return ;
}

/***Destructor***/
Weapon::~Weapon()
{
	return ;
}


std::string	Weapon::getType(void) const
{
	// std::string &ref = this->_type;
	// return ref;
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
