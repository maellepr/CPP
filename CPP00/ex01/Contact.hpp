/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:12:28 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/14 17:12:53 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>


class	Contact {
	public :
		Contact();
		~Contact();
		void		setFirstName(std::string str);
		void		setLastName(std::string str);
		
		std::string	getFirstName();
		std::string	getLastName();

	private :
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkSecret;
		
};

#endif
