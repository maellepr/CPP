/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:31:13 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/22 10:32:43 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	public :
		HumanB(std::string name);//constructeur sans weapon
		~HumanB();//destructeur
	
		void	attack() const;
		void	setWeapon( Weapon &aWeapon );
	private :
		std::string	_name;
		Weapon		*_weapon;//pointeur car weapon parfois nulle 
};

#endif