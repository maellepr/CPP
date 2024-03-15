/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:41:28 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/15 16:50:07 by mapoirie         ###   ########.fr       */
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
			bool		printContactList(void) const;
			void		printTableStr(std::string str) const;
			bool		isNumber(std::string str) const;
			bool		isValidNumber(std::string str) const ;
			void		printContactInfos(std::string str) const;
			
	private ://mettre en prive toutes les fonctons/attributs utilise seulement dans PhoneBook.cpp
			bool		_continue;
			int			_index;
			Contact		_contact[8];
			
	
};

#endif