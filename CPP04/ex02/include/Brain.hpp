#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include "Animal.hpp"

class Brain
{
	public :
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain	&	operator=(Brain const & src);

		void				setIdeas(int i, std::string const & idea);
		std::string const	getIdea(int i) const;

		static int const	nb_ideas = 100;
	private :
		std::string	_ideas[100];
};

#endif