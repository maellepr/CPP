/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:04 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/15 17:18:47 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : _continue(true), _index(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool	PhoneBook::printContactList(void) const
{
	if (this->_contact[0].isEmptyLine())
	{
		std::cout << std::endl << "      ••••• No contact saved yet ! ••••• " << std::endl;
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
			printTableStr(_contact[i - 1].getFirstName()); 
			std::cout <<"║";
			printTableStr(_contact[i - 1].getLastName());
			std::cout <<"║";
			printTableStr(_contact[i - 1].getNickname()); 
			std::cout <<"║" << std::endl;
		}
	}
	std::cout	<< "╚══════════╩══════════╩══════════╩══════════╝" << std::endl;
	return (true);
}

void	PhoneBook::printTableStr(std::string str) const
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str ;
	return ;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;

	if (!printContactList())
		return ;
	std::cout << std::endl << "|~-~-~-~-~-~-~- Search contact -~-~-~-~-~-~-~|" << std::endl << std::endl;

	while (1)
	{
		input = getInput("index number you would like to display");
		if (input.size() == 1 && isNumber(input) && isValidNumber(input))
			break ;
	}
	printContactInfos(input);
}

void	PhoneBook::printContactInfos(std::string str) const
{
	int	index = str[0] - '0';

	std::cout << std::endl << "           ••••• Contact nº" << index << " •••••           " << std::endl;
	std::cout << "First Name : " << this->_contact[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name : " << this->_contact[index - 1].getLastName() << std::endl;
	std::cout << "Nickname : " << this->_contact[index - 1].getNickname() << std::endl;
	std::cout << "Phone number : " << this->_contact[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << this->_contact[index - 1].getDarkSecret() << std::endl << std::endl;
}

bool PhoneBook::isValidNumber(std::string str) const
{
	int	index = str[0] - '0';

	if (index <= this->_index)
		return (true);
	return (false);
}

bool	PhoneBook::isNumber(std::string str) const
{
	if (str[0] >= '1' && str[0] <= '9')
		return (true);
	return (false);
}

std::string	PhoneBook::getInput(std::string const message)
{
	std::string	input;

	std::cout << std::endl << " Please enter the contact " << message << " :" << std::endl << std::endl;
	if (!std::getline(std::cin, input))//ajouter protection + ajouter trim
	{
		this->_continue = true;//var qui permet de faire des boucles
		return (std::string());	
	}
	// this->_continue = false;
	return (input);
}

void	PhoneBook::addContact(void)
{
	// Contact	contact;//on cree un contact de type Contact
	std::string	input;

	std::cout << std::endl << "|~-~-~-~-~-~-~ New contact menu ~-~-~-~-~-~-~|" << std::endl << std::endl;
	while (1)
	{
		input = getInput("first name");
		if (!this->_contact[_index].setFirstName(input))
			break ;
	}
	while (1)
	{
		input = getInput("last name");
		if (!this->_contact[_index].setLastName(input))
			break ;
	}
	while (1)
	{
		input = getInput("nickname");
		if (!this->_contact[_index].setNickname(input))
			break ;
	}
	while (1)
	{
		input = getInput("phone number");
		if (!this->_contact[_index].setPhoneNumber(input))
			break ;
	}
	while (1)
	{
		input = getInput("darkest secret");
		if (!this->_contact[_index].setDarkSecret(input))
			break ;
	}
	std::cout << " Contact nº" << _index + 1 << " saved !" << std::endl;
	this->_index++;
	if (_index > 7)
		this->_index = 0;
	
	//std::cout << "contact 0 first name : " << _contact[0]._FirstName << std::endl; 
	//faire un get pour pouvoir acceder au var
	return ;
}