#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
		try
		{
			ScalarConverter::convert(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	else 
		std::cout << "The program take only one argument" << std::endl;
	return (0);
}