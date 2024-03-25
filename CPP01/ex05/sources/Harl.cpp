/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:04:43 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 11:40:28 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*********** CONSTRUCTOR **********/
Harl::Harl()
{
	_complaints[0] = &Harl::_debug;
	_complaints[1] = &Harl::_info;
	_complaints[2] = &Harl::_warning;
	_complaints[3] = &Harl::_error;
	return ;
}

/*********** DESTRUCTOR ***********/
Harl::~Harl()
{
	return ;
}

/******** PUBLIC FUNCTIONS *******/
void	Harl::complain(std::string level)
{
	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
			(this->*_complaints[i])();
	}
}

/******* PRIVATE FUNCTIONS *******/
void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}