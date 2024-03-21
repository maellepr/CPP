/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:26:52 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/21 17:16:48 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	public :
		// HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack() const;
		
	private :
		std::string	_name;
		Weapon		&_weapon;
	
};


#endif