#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include "Animal.hpp"

class Brain
{
	public :
		Brain(void);
		Brain(std::string type);
		Brain(Brain const & src);
		virtual ~Brain(void);

		Brain	&	operator=(Brain const & src);


	private :
		std::string	_ideas[100];
};

#endif