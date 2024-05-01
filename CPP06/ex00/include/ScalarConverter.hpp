#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>

class ScalarConverter
{
	public:
		static void	convert(std::string str);
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter &operator=(ScalarConverter const & src);
		~ScalarConverter(void);

};

void	printIsEmpty(void);

bool	isPseudoLit(std::string str);
void	printFromPseudoLit(std::string str);

bool	isChar(std::string str);
void	printFromChar(std::string str);

bool	isInt(std::string str);
void	printFromInt(std::string str);

bool	isFloat(std::string str);
void	printFromFloat(std::string str);

bool	isDouble(std::string str);
void	printFromDouble(std::string str);

#endif
