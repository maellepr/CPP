/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:43:10 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/19 14:15:17 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) : _FirstName(""), _LastName(""), _Nickname(""), _PhoneNumber(""), _DarkSecret("")
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

bool	Contact::setFirstName(std::string str)
{
	if (str.empty() || !_isLetter(str, "first name"))
		return true;
	this->_FirstName = str;
	return false;
}

bool	Contact::setLastName(std::string str)
{
	if (str.empty() || !_isLetter(str, "last name"))
		return true;
	this->_LastName = str;
	return false;
}

bool	Contact::setNickname(std::string str)
{
	if (str.empty() || !_isLetter(str, "nickname"))
		return true;
	this->_Nickname = str;
	return false;
}

bool	Contact::setPhoneNumber(std::string str)
{
	if (str.empty() || !_isNumber(str, "phone number"))
		return true;
	this->_PhoneNumber = str;
	return false;
}

bool	Contact::setDarkSecret(std::string str)
{
	if (str.empty() || !_isLetter(str, "darkest secret"))
		return true;
	this->_DarkSecret = str;
	return false;
}

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

bool	Contact::isEmptyLine(void) const
{
	if(this->_FirstName.empty() || this->_LastName.empty() ||
		this->_Nickname.empty() || this->_PhoneNumber.empty() ||
		this->_PhoneNumber.empty())
		return (true);
	return (false);
}

bool	Contact::_isLetter(std::string const str, std::string const info) const
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
		{
			std::cout << "◢!◣The " << info << " has to be only letters◢!◣" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	Contact::_isNumber(std::string const str, std::string const info) const
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			std::cout << "◢!◣The " << info << " has to be only digits◢!◣" << std::endl;
			return (false);
		}
	}
	return (true);
}
