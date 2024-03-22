/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:21:34 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/22 09:33:34 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	public :
		Weapon(std::string wType);
		~Weapon();
		std::string	getType() const;
		void		setType(std::string newType);

	private :
		std::string	_type;//type d'arme
};


#endif