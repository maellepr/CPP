/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:04 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/19 15:38:40 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : to_continue(true), _index(0), _index2(0)
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
	this->to_continue = true;

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
	if (_index2 < 8)
		this->_index2++;
	return ;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	this->to_continue = true;

	if (!_printContactList())
		return ;
	std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
	std::cout << 			  "│  (•ิ_•ิ)?  ┌ ┌ Search contact ┐ ┐          │" << std::endl;
	std::cout			   << "└──────────────────────────────────────────┘" << std::endl;
	while (to_continue)
	{
		input = _getInput("index number you would like to display");
		// std::cout << "input.size = " << input.size() << " is number:" << _isNumber(input) << " is valid number:" << _isValidNumber(input) << std::endl;
		if (!to_continue || (input.size() == 1 && _isNumber(input) && _isValidNumber(input)))
			break ;
		if (this->_index2 == 1)
			std::cout << std::endl << " You can only choose contact [1] because only one contact has been saved !" << std::endl;
		else
			std::cout << std::endl << " It should be a number between 1 and " << this->_index2 << std::endl;
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
	std::cout << std::endl << "╔══════════╦══════════╦══════════╦══════════╗" << std::endl
						   << "║   INDEX  ║FIRST NAME║LAST  NAME║ NICKNAME ║" << std::endl;
	
	for (int i = 1; i < 9; i++)
	{
		if (!this->_contact[i - 1].isEmptyLine())
		{
			std::cout << "╠══════════╬══════════╬══════════╬══════════╣" << std::endl
			<< "║       [" << i << "]║";
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

	// std::cout << " is ValidNumber index = " << index << "  this->index2 = " << this->_index2 << std::endl;
	if (index <= this->_index2)
		return (true);
	return (false);
}
