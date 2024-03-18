/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:12:28 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/18 14:24:24 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>


class	Contact {
	public :
		Contact();
		~Contact();
		bool		setFirstName(std::string str);
		bool		setLastName(std::string str);
		bool		setNickname(std::string str);
		bool		setPhoneNumber(std::string str);
		bool		setDarkSecret(std::string str);
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string getPhoneNumber() const;
		std::string	getDarkSecret() const;
		bool		isEmptyLine() const;
	private :
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkSecret;

		bool		_isLetter(std::string const str, std::string const info) const;
		bool		_isNumber(std::string const str, std::string const info) const;
};

#endif
