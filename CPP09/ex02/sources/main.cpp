#include "../include/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		PmergeMe MI;
		
		try
		{
			MI.MergeInsertion(ac, av);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
		std::cout << "The program must take at least one argument" << std::endl;
	return 0;
}