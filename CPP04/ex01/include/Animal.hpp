#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <iomanip>

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

class Animal {
	public :
		Animal(void);
		Animal(std::string const & type);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &	operator=(Animal const & src);
		
		std::string const	& getType(void) const;

		virtual void	makeSound(void) const;

		std::string	*color;
	protected :
		std::string	_type;
		void	getColor(void);
};

#endif