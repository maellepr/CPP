#include "../include/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;
	
	if (ac == 2)
	{
		try
		{
			btc.initDatabase();
			btc.readInputFile(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}