/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:43:10 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/14 15:56:40 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) /*: _FirstName("")*/
{
	
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setFirstName(std::string str)
{
	this->_FirstName = str;
	return ;
}