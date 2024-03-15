/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:19:10 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/15 16:56:06 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>// pour utiliser cin et cout
#include <string>//pour utiliser string class

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	user_input;
	

	std::cout << std::endl << "|~-~-~-~- Welcome to the PhoneBook ! -~-~-~-~|" << std::endl;
	while (1)
	{
			std::cout << std::endl << "  What would you like to do ?" << std::endl << std::endl;
			std::getline(std::cin, user_input);//a voir que faire lorsque !user_input
			if (user_input == "ADD")
				book.addContact();
			else if (user_input == "SEARCH")
				book.searchContact();
			else if (user_input == "EXIT")
				break;
			else
			{
				std::cout << std::endl << "  Choose one of this command:" << std::endl
						<< "    «	ADD	» to add a contact" << std::endl
						<< "    «	SEARCH	» to search in the contact list" << std::endl
						<< "    «	EXIT	» to exit the PhoneBook" << std::endl;
			}
	}
	std::cout << "|~-~-~ Thanks for using the PhoneBook ! ~-~-~|" << std::endl;
	return (0);
}
