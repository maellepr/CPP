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

void	BitcoinExchange::initDatabase(void)
{
	std::ifstream	ifs("data.csv");
	
	if (!ifs.is_open())
		throw ErrorDatabase();

	std::string		line;
	std::getline(ifs, line);

	while(std::getline(ifs, line))
	{
		std::istringstream ss(line);
		std::string	date;
		float		value;

		date = line.erase(10);
		ss.ignore(11);
		ss >> value;
		_data[date] = value;
	}
}

int	BitcoinExchange::readInputFile(std::string file)
{	
	std::ifstream	ifs(file.c_str());
	std::string		line;
	std::string		date;
	std::string		pipe;
	std::string		value;
	float			fvalue;

	if (!ifs.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	bool i = false;
	while (std::getline(ifs, line))
	{
		if (line == "date | value" && i == false)
		{
			std::getline(ifs, line);
		}
		i = true;

		std::istringstream	iss(line);
		iss >> date >> pipe >> value;
		// std::cout << "date = " << date << " pipe = " << pipe << " value = " << value << std::endl;
		try
		{
			_checkLine(line);
			_checkDate(date);
			_checkPipe(pipe);
			fvalue = _checkValue(value);		
			
			std::map<std::string, float>::iterator itlow;
			itlow = _data.lower_bound(date);
			if (itlow->first != date && itlow != _data.begin())
				itlow--;
		
			std::cout << date << " => " << fvalue << " = " << fvalue * itlow->second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what();
			std::string exception = e.what();
			if (exception == "bad input")
				std::cerr << " => " << line;
			std::cerr << std::endl;
		}

	}
	return 0;
}

void	BitcoinExchange::_checkLine(const std::string line) const
{
	int	space = 0;

	if (!line.size() || line.size() < 14)
			throw BadInput();
	for(unsigned int i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ')
			space++;
	}
	if (space > 2)
		throw BadInput();
}

void	BitcoinExchange::_checkDate(const std::string date) const
{
	// std::cout << "<" << date << ">" << std::endl;
	if (date.size() != 10 || (date.size() > 5 && date[4] != '-') || (date.size() > 8 && date[7] != '-'))
	{
		// std::cout << "Format error : date.size = " << date.size() << "\n";
		throw BadInput();
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && (i == 0 || i == 1 || i == 2 
		|| i == 3 || i == 5 || i == 6 || i == 8 || i == 9))
			throw BadInput();
	}

	std::istringstream	ss(date);
	int			year;
	int			month;
	int			day;
	ss >> year;
	ss.ignore();
	ss >> month;
	ss.ignore();
	ss >> day;
	if (!year || !month || !day)
		throw BadInput();
	// std::cout << "<" << year << month << day << ">" << std::endl;
	if ((year < 2009 && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) || date == "2009-01-01")
		throw DateAbove();
	if (year > 2022 || (year == 2022 && month > 3) || ( year == 2022 && month == 3 && (day > 29 && day < 32)))
		throw DateBelow();
	if (month < 1 || month > 12)
		throw BadInput();
	if (day < 1 || day > 31)
		throw BadInput();
	if (year % 4 != 0 && month == 2 && day > 28)
	{
		// std::cout << "annee non bissextile\n";
		throw BadInput();//annee non bissextile
	}
	if (year % 4 == 0 && month == 2 && day > 29)
	{
		// std::cout << "annee bissextile \n";
		throw BadInput();//annee bissextile
	}
	if (month % 2 == 0 && day > 30)
	{
		// std::cout << "mois pairs\n";
		throw BadInput();
	}
	// std::cout << month << std::endl;
	// std::cout << day << std::endl;
}

void	BitcoinExchange::_checkPipe(const std::string pipe) const
{
	if (pipe.size() != 1 || pipe[0] != '|')
		throw BadInput();
}

float	BitcoinExchange::_checkValue(const std::string value) const
{
	// std::cout << "<" << value << ">" << std::endl;
	if (!value.size())
		throw BadInput();

	int	isFloat = 0;
	int	signNeg = 0;
	for (unsigned int i = 0; i < value.size(); i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.' && value[i] != '-')
			throw BadInput();
		if (value[i] == '.')
			isFloat++;
		if (value[i] == '-')
			signNeg++;
	}
	if ((isFloat != 1 && isFloat != 0) || (signNeg != 0 && signNeg != 1) || value == "-" || value == "." 
	|| (value[0] == '.') || (value[value.size() - 1] && (value[value.size() - 1] == '.' || value[value.size() - 1] == '-')))
		throw BadInput();
	std::istringstream	ss(value);

	float nbfValue;
	ss >> nbfValue;
	if (nbfValue < 0.0) 
		throw NotPositiveNb();
	if (nbfValue > 1000.0)
		throw TooLargeNb();

	return (nbfValue);
}
