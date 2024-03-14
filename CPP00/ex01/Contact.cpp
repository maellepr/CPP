/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:43:10 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/14 17:24:35 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) /*: _FirstName("")*/
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getLastName(void)
{
	return (this->_LastName);
}

std::string	Contact::getFirstName(void)
{
	return (this->_FirstName);
}

void	Contact::setLastName(std::string str)
{
	this->_LastName = str;
	return ;
}

void	Contact::setFirstName(std::string str)
{
	this->_FirstName = str;
	return ;
}