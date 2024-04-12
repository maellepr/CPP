#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
	public :
		Character(void);
		Character(Character const & character);
		virtual ~Character(void);

		Character &	operator=(Character const & src);
		

	protected :
		std::string	_name;//
};

#endif