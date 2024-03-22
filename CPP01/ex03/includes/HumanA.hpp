/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:26:52 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/22 10:19:04 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	public :
		HumanA(std::string name, Weapon &weapon);//constructeur tjrs avec weapon
		~HumanA();//destructeur

		void	attack() const;
	private :
		std::string	_name;		
		Weapon		&_weapon;//ref car _weapon jamais nulle

};


#endif