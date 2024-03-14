/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:04 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/14 17:25:39 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::printContactList(void)
{
	std::cout	<< "╔══════════╦══════════╦══════════╦══════════╗" << std::endl
				<< "║   INDEX  ║FIRST NAME║LAST  NAME║ NICKNAME ║" << std::endl
				<< "╚══════════╩══════════╩══════════╩══════════╝" << std::endl
				<< "║    [0]   ║"	<< _contact[0].getFirstName()
									<< _contact[0].getLastName()
									/*<< _contact[0].getNickName */<< std::endl;
	
}

void	PhoneBook::searchContact(void)
{
	printContactList();
}

std::string	PhoneBook::getInput(std::string const message)
{
	std::string	input;

	std::cout << " Please enter the contact " << message << " : " << std::endl;
	if (!std::getline(std::cin, input))//ajouter protection + ajouter trim
	{
		this->_continue = 1;//var qui permet de faire des boucles
		return (std::string());	
	}
	this->_continue = 0;
	return (input);
}

void	PhoneBook::addContact(void)
{
	// Contact	contact;//on cree un contact de type Contact
	this->_continue = 1;
	
	std::string	input;

	std::cout << std::endl << "|~-~-~-~-~-~ New contact menu ~-~-~-~-~-~|" << std::endl << std::endl;
	while (_continue == 1)
	{
		input = getInput("first name");
		this->_contact[0].setFirstName(input);
	}
	this->_continue = 1;
	while (_continue == 1)
	{
		input = getInput("last name");
		this->_contact[0].setLastName(input);
	}
	std::cout << " Contact first name saved !" << std::endl;
	
	
	//std::cout << "contact 0 first name : " << _contact[0]._FirstName << std::endl; 
	//faire un get pour pouvoir acceder au var
	return ;
}