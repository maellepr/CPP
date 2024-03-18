/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:04 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/18 14:33:37 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : to_continue(true), _index(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(void)
{
	std::string	input;

	std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
	std::cout <<			  "│ ･｡.･ﾟﾟ･｡. New contact menu ･ﾟﾟ･｡.･ﾟﾟ･｡.  │" << std::endl;
	std::cout			   << "└──────────────────────────────────────────┘" << std::endl;
	while (to_continue)
	{
		input = _getInput("first name");
		if (!to_continue || !this->_contact[_index].setFirstName(input))
			break ;
	}
	while (to_continue)
	{
		input = _getInput("last name");
		if (!to_continue || !this->_contact[_index].setLastName(input))
			break ;
	}
	while (to_continue)
	{
		input = _getInput("nickname");
		if (!to_continue || !this->_contact[_index].setNickname(input))
			break ;
	}
	while (to_continue)
	{
		input = _getInput("phone number");
		if (!to_continue || !this->_contact[_index].setPhoneNumber(input))
			break ;
	}
	while (to_continue)
	{
		input = _getInput("darkest secret");
		if (!to_continue || !this->_contact[_index].setDarkSecret(input))
			break ;
	}
	if (!to_continue)
		return ;
	std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
	std::cout << "│   Contact nº" << _index + 1 << " saved ! 	(◕‿◕)♡     │" << std::endl;
	std::cout			   << "└──────────────────────────────────────────┘" << std::endl;
	this->_index++;
	if (_index > 7)
		this->_index = 0;
	return ;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;

	if (!_printContactList())
		return ;
	std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
	std::cout << 			  "│  (•ิ_•ิ)?  ┌ ┌ Search contact ┐ ┐          │" << std::endl;
	std::cout			   << "└──────────────────────────────────────────┘" << std::endl;
	while (to_continue)
	{
		input = _getInput("index number you would like to display");
		if (!to_continue || (input.size() == 1 && _isNumber(input) && _isValidNumber(input)))
			break ;
	}
	if (to_continue)
		_printContactInfos(input);
}

std::string	PhoneBook::_getInput(std::string const message)
{
	std::string	input;

	std::cout << std::endl << " Please enter the contact " << message << " :" << std::endl << std::endl;
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		this->to_continue = false;
		return (std::string());
	}
	return (input);
}

bool	PhoneBook::_printContactList(void) const
{
	if (this->_contact[0].isEmptyLine())
	{
		std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
		std::cout << 			  "│   • • •• No contact saved yet ! •• • •   │" << std::endl;
		std::cout			   << "└──────────────────────────────────────────┘" << std::endl;
		return (false);
	}
	std::cout	<< "╔══════════╦══════════╦══════════╦══════════╗" << std::endl
				<< "║   INDEX  ║FIRST NAME║LAST  NAME║ NICKNAME ║" << std::endl;
	
	for (int i = 1; i < 9; i++)
	{
		if (!this->_contact[i - 1].isEmptyLine())
		{
			std::cout << "╠══════════╬══════════╬══════════╬══════════╣" << std::endl
			<< "║    [" << i << "]   ║";
			_printTableStr(_contact[i - 1].getFirstName()); 
			std::cout <<"║";
			_printTableStr(_contact[i - 1].getLastName());
			std::cout <<"║";
			_printTableStr(_contact[i - 1].getNickname()); 
			std::cout <<"║" << std::endl;
		}
	}
	std::cout	<< "╚══════════╩══════════╩══════════╩══════════╝" << std::endl;
	return (true);
}

void	PhoneBook::_printTableStr(std::string str) const
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str ;
	return ;
}

void	PhoneBook::_printContactInfos(std::string str) const
{
	int	index = str[0] - '0';

	std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
	std::cout << 			  "│          .｡.:* Contact nº" << index << " °˖✧◝          │" << std::endl;
	std::cout			   << "└──────────────────────────────────────────┘" << std::endl;

	std::cout << " ★ First Name : " << this->_contact[index - 1].getFirstName() << std::endl;
	std::cout << " □ Last Name : " << this->_contact[index - 1].getLastName() << std::endl;
	std::cout << " ▽ Nickname : " << this->_contact[index - 1].getNickname() << std::endl;
	std::cout << " ◎ Phone number : " << this->_contact[index - 1].getPhoneNumber() << std::endl;
	std::cout << " ψ Darkest Secret : " << this->_contact[index - 1].getDarkSecret() << std::endl << std::endl;
}

bool	PhoneBook::_isNumber(std::string str) const
{
	if (str[0] >= '1' && str[0] <= '9')
		return (true);
	return (false);
}

bool PhoneBook::_isValidNumber(std::string str) const
{
	int	index = str[0] - '0';

	if (index <= this->_index)
		return (true);
	return (false);
}
