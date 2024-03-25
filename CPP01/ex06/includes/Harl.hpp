/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:45:11 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 13:47:48 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl 
{
	public :
		Harl();
		~Harl();
		std::string level[4];
		void	complain(int level);

	private :
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);	
};

#endif