/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:21:34 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 17:12:26 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	public :
		// Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string	getType(void) const;
		void		setType(std::string type);

	private :
		std::string	_type;
};


#endif