#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

#define BOLD	"\e[1m"
#define DIM		"\e[2m"
#define ITAL	"\e[3m"
#define ULINE	"\e[4m"

#define	YELLOW	"\e[38;2;217;255;0m"
#define	PINK	"\e[38;2;255;0;89m"
#define PURPLE	"\e[38;2;255;0;217m"
#define	GREEN	"\e[38;2;89;255;0m"
#define	RED		"\e[38;2;255;38;0m"
#define ORANGE	"\e[38;2;255;166;0m"

#define RESET	"\e[0m"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria &	operator=(AMateria const & materia);
		virtual ~AMateria(void);


		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif