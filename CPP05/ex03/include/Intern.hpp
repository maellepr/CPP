#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern & operator=(Intert const & src);
	
		Form* makeForm(std::string formName, std::string formTarget);
	private:
};

#endif