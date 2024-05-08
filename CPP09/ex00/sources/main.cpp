#include "../include/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;
	
	if (ac == 2)
	{
		try {
			btc.readInputFile(av[1]);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		// if (printData() == 1)
		// 	return 1;
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}