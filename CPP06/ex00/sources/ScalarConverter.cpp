#include "../include/ScalarConverter.hpp"

bool	isPseudoLit(std::string str)
{
	std::string p[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (p[i] == str)
			return (true);
	}
	return (false);
}

void	printPseudoLit(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.erase(str.size() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	return ;
}

bool	isChar(std::string str)
{
	if (str.size() == 1)
	{
		if (str[0] >= 0 && str[0] <= 127)
			return (true);
	}
	return (false);
}

void	printChar(std::string str)
{
	std::cout << "char: " << str[0] << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	if (str.empty())
		throw std::invalid_argument("Argument is empty");
	if (isPseudoLit(str))
		printPseudoLit(str);
	else if (isChar(str))
		printChar(str);
	return ;
}

