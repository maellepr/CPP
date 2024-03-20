/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:49:57 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/20 16:40:55 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
    public :
        Zombie();
        ~Zombie();
        
		void	announce(void);
		
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);
    
	private :
        std::string _name;
    
};

#endif