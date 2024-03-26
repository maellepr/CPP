/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:57:50 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 15:15:15 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Adress :" << std::endl
			  << &string << std::endl
			  << stringPTR << std::endl
			  << &stringREF << std::endl << std::endl;
	std::cout << "Content :" << std::endl
			  << string << std::endl 
			  << *stringPTR << std::endl
			  << stringREF << std::endl;
}