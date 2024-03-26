/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:03:28 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:27:19 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	Harl;

	std::cout << "DEBUGGING MESSAGE :" << std::endl;
	Harl.complain("DEBUG");
	std::cout << std::endl << "INFO MESSAGE :" << std::endl;
	Harl.complain("INFO");
	std::cout << std::endl << "WARNING MESSAGE :" << std::endl;
	Harl.complain("WARNING");
	std::cout << std::endl << "ERROR MESSAGE :" << std::endl;
	Harl.complain("ERROR");
}