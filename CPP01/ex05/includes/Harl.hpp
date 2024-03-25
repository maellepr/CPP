/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:04:48 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 11:40:32 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	public :
		Harl();
		~Harl();
		void	complain(std::string level);

	private :
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
		typedef void (Harl::*ptr_f)(void);
		ptr_f	_complaints[4];
		//tableau de 4 qui va pointer sur chaques fonctions
};

#endif