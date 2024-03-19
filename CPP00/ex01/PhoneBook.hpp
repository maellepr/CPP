/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:41:28 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/19 14:09:01 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class	PhoneBook {
	public :
			PhoneBook(void);
			~PhoneBook(void);
			bool		to_continue;
			void		addContact(void);			
			void		searchContact(void);	
	private :
			int			_index;
			int			_index2;
			Contact		_contact[8];
			std::string	_getInput(std::string const message);
			bool		_printContactList(void) const;
			void		_printTableStr(std::string str) const;
			void		_printContactInfos(std::string str) const;
			bool		_isNumber(std::string str) const;
			bool		_isValidNumber(std::string str) const;
};

#endif