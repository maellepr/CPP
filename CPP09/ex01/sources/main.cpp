#include "../include/RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn;

		try
		{
			rpn.checkError(av[1]);
			rpn.doCalcul(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
		std::cout << "The program must take one argument" << std::endl;
	return 0;
}