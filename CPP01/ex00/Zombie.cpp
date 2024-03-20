/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:03:54 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:36 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) :
{
	
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << "has been destroyed !" << std::endl;
	return ;
}

void	announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
	Zombie	*Foo = new Zombie;

	Foo->_name = name;
	return (Foo);
}

void	Zombie::randomChump(std::string name)
// on peut creer un zombie en ref car pas besoin 
//de l'utiliser ailleurs que dans cette fonction ?
{

}