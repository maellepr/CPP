#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	if (this != &src)
		*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

int	BitcoinExchange::readInputFile(std::string file)
{
	std::ifstream	ifs(file.c_str());
	std::string		line;
	std::string		date;
	std::string		pipe;
	std::string		value;

	if (!ifs.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::getline(ifs, line);
	// std::istringstream iss(line);
	// iss >> date >> pipe >> value;
	// if (date != "date" || pipe != "|" || value != "value")
	// 	std::cout << ""
	while (std::getline(ifs, line))
	{
		std::istringstream iss(line);
		iss >> date >> pipe >> value;
		try
		{
			_checkDate(date);			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		
	}


	return 0;
}

void	BitcoinExchange::_checkDate(const std::string date) const
{
	std::cout << "<" << date << ">" << std::endl;
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw WrongDateFormat();

	std::istringstream	ss(date);
	int			year;
	int			month;
	int			day;
	ss >> year;
	std::cout << year << std::endl;
	if (year < 2009 || year > 2022)
		throw WrongDateFormat();
	ss >> month;
	std::cout << month << std::endl;
	ss >> day;
	std::cout << day << std::endl;
}
