/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:19:10 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/18 12:08:05 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>// pour utiliser cin et cout
#include <string>//pour utiliser string class

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string getFirstInput(PhoneBook book)
{
	std::string	user_input;
	
	if (!std::getline(std::cin, user_input) || std::cin.eof())
	{
		book.to_continue = false;
		return ("EXIT");
	}
	return (user_input);
}

int main(void)
{
	PhoneBook	book;
	std::string	user_input;
	
	std::cout << std::endl << "╔══════════════════════════════════════════╗" << std::endl;
	std::cout << "║(╯✧▽✧)╯ Welcome to \e[1m\e[5mBipBipPhoneBook\e[0m\e[0m! ~(☆ω☆)║" << std::endl;
	std::cout << "╚══════════════════════════════════════════╝" << std::endl;
	// std::cout << std::endl << "|~-~-~-~- Welcome to the PhoneBook ! -~-~-~-~|" << std::endl;
	while (book.to_continue)
	{
			std::cout << std::endl << "  What would you like to do ?" << std::endl << std::endl;
			
			user_input = getFirstInput(book);
			if (user_input == "ADD")
				book.addContact();
			else if (user_input == "SEARCH")
				book.searchContact();
			else if (user_input == "EXIT")
				break;
			else
			{
				
				std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
				std::cout			   << "│  Choose one of this command:             │" << std::endl;
				std::cout			   << "│                                          │" << std::endl;
				std::cout			   << "│  ☆	ADD	☆   to add a contact       │" << std::endl;
				std::cout			   << "│  ☆	SEARCH	☆   to search a contact    │" << std::endl;
				std::cout 			   << "│  ☆	EXIT	☆   to exit the PhoneBook  │" << std::endl;
				std::cout			   << "└──────────────────────────────────────────┘" << std::endl;
			}
	}
	std::cout << std::endl << "╔══════════════════════════════════════════╗" << std::endl;
	std::cout << "║ Thanks for using \e[1m\e[5mBipBipPhoneBook\e[0m\e[0m! (❤ω❤)  ║" << std::endl;
	std::cout << "╚══════════════════════════════════════════╝" << std::endl;
	return (0);
}
