/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:49:57 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:06:10 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
    public :
		Zombie (void);//constructeur par defaut
		Zombie(std::string name);//constructeur
		~Zombie();//destructeur
		void	announce(void);
	private :
        std::string _name;
    
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif