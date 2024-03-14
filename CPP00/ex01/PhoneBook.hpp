/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:41:28 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/14 16:47:55 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class	PhoneBook {
	public :
			PhoneBook(void);//constructeur
			~PhoneBook(void);//destructeur

			void		addContact(void);
			void		searchContact(void);

			std::string	getInput(std::string const message);
			// print la string const a recuperer, la recup et la renvoie
			void		printContactList(void);

			
	private ://mettre en prive toutes les fonctons/attributs utilise seulement dans PhoneBook.cpp
			int			_continue;
			Contact		_contact[8];
			
	
};

#endif