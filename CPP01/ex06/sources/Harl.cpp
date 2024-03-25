/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:44:52 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 14:06:58 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*********** CONSTRUCTOR **********/
Harl::Harl()
{
	this->level[0] = "DEBUG";
	this->level[1] = "INFO";
	this->level[2] = "WARNING";
	this->level[3] = "ERROR";
	return ;
}

/*********** DESTRUCTOR ***********/
Harl::~Harl()
{
	return ;
}

/******** PUBLIC FUNCTIONS *******/
void	Harl::complain(int level)
{
	switch (level) {
        case 1:
            Harl::_debug();
        case 2:
        	Harl::_info();
        case 3:
            Harl::_warning();
		case 4:
			Harl::_error();
			break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

/******* PRIVATE FUNCTIONS *******/
void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl 
			  << "I really do !" << std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn’t put enough bacon in my burger !" << std::endl 
			  << "If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free." << std::endl
			  << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}