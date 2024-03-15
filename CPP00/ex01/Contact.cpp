/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:43:10 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/15 12:07:04 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) /*: _FirstName(""), _LastName(""), _Nickname(""), _PhoneNumber(""), _DarkSecret("")*/
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

// ----------------- set ---------------------//

bool	Contact::setFirstName(std::string str)
{
	if (str.empty())
		return true;//continuer de checher l'input
	this->_FirstName = str;
	return false;//arreter input
}

bool	Contact::setLastName(std::string str)
{
	if (str.empty())
		return true;
	this->_LastName = str;
	return false;
}

bool	Contact::setNickname(std::string str)
{
	if (str.empty())
		return true;
	this->_Nickname = str;
	return false;
}

bool	Contact::setPhoneNumber(std::string str)
{
	if (str.empty())
		return true;
	this->_PhoneNumber = str;
	return false;
}

bool	Contact::setDarkSecret(std::string str)
{
	if (str.empty())
		return true;
	this->_DarkSecret = str;
	return false;
}
// -------------------------------------------//

// ----------------- get ---------------------//

std::string	Contact::getFirstName(void) const
{
	return (this->_FirstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_LastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_Nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_PhoneNumber);
}

std::string Contact::getDarkSecret(void) const
{
	return (this->_DarkSecret);
}

// -------------------------------------------//
#include <iostream>

bool	Contact::isEmptyLine(void) const
{
	if(this->_FirstName.empty() || this->_LastName.empty() ||
		this->_Nickname.empty() || this->_PhoneNumber.empty() ||
		this->_PhoneNumber.empty())
	{
		// std::cout << "send true" << std::endl;
		return (true);
	}
	else
		return (false);
}