#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

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

void	printFromPseudoLit(std::string str)
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

void	printFromChar(std::string str)
{
	std::cout << "char: '" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

bool	isInt(std::string str)
{
	size_t		i = 0;
	int			nb;
	long int	nbl;
	if (str[i] == '-' || str[i] == '+')
		i++;
	
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	std::istringstream stream(str);
	std::istringstream lstream(str);
	if ((stream >> nb).fail())
		return (false);
	lstream >> nbl;
	if (nbl < std::numeric_limits<int>::min() || nbl > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

void	printFromInt(std::string str)
{
	int	nb;
	std::istringstream stream(str);
	stream >> nb;	

	if ((nb >= 0 && nb < 32) || nb == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (nb >= 32 && nb <= 126)
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}

bool	isFloat(std::string str)
{
	size_t	i = 0;
	int		point = 0;
	float	nbf;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != 'f')
			return (false);
		if (str[i] == '.')
			point++;
		if (point > 1)
			return (false);
		if (str[i] == 'f' && str[i + 1] != '\0')
			return (false);
		i++;
	}
	if (point != 1 || str[i - 1] != 'f')
		return (false);
	std::istringstream fstream(str.erase(str.size() - 1));
	if ((fstream >> nbf).fail())
		return (false);
	if (nbf < -std::numeric_limits<float>::max() || nbf > std::numeric_limits<float>::max())
		return (false);
	return (true);
}

void	printFromFloat(std::string str)
{
	float	nbf;
	
	std::istringstream streamf(str.erase(str.size() - 1));
	streamf >> nbf;

	if (nbf < 32 || nbf > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbf) << "'" << std::endl;

	if (nbf >= std::numeric_limits<int>::min() && nbf < std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(nbf) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (nbf == static_cast<int>(nbf))
		std::cout << "float: " << nbf << ".0f" << std::endl;
	else
		std::cout << "float: " << nbf << "f" << std::endl;

	if (nbf == static_cast<int>(nbf))
		std::cout << "double: " << nbf << ".0" << std::endl;
	else
		std::cout << "double: " << nbf << std::endl;
}

bool	isDouble(std::string str)
{
	size_t	i = 0;
	int		point = 0;
	double	nbd;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
		if (str[i] == '.')
			point++;
		if (point > 1)
			return (false);
		i++;
	}
	if (point != 1)
		return (false);
	std::istringstream fstream(str.erase(str.size() - 1));
	if ((fstream >> nbd).fail())
		return (false);
	if (nbd < -std::numeric_limits<double>::max() || nbd > std::numeric_limits<double>::max())
		return (false);
	return (true);
}

void	printFromDouble(std::string str)
{
	double	nbd;

	std::istringstream dstream(str);
	dstream >> nbd;
	if (nbd < 32 || nbd > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbd) << "'" << std::endl;
	
	std::istringstream stream(str);
	if (nbd < static_cast<long>(std::numeric_limits<int>::min()) || nbd > static_cast<long>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(nbd) << std::endl;
	std::istringstream fstream;
	
	if (nbd < -static_cast<double>(std::numeric_limits<float>::max()) || nbd > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else if (static_cast<float>(nbd) == static_cast<int>(nbd))
		std::cout << "float: " << static_cast<float>(nbd) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(nbd) << "f" << std::endl;
	
	if (nbd == static_cast<int>(nbd))
		std::cout << "double: " << nbd << ".0" << std::endl;
	else
		std::cout << "double: " << nbd << std::endl;
	return ;
}

void	ScalarConverter::convert(std::string str)
{
	if (str.empty())
		throw std::invalid_argument("Argument is empty");
	if (isPseudoLit(str))
		printFromPseudoLit(str);
	else if (isInt(str))
		printFromInt(str);	
	else if (isChar(str))
		printFromChar(str);
	else if (isFloat(str))
		printFromFloat(str);
	else if (isDouble(str))
		printFromDouble(str);
	else
	{
		std::cout << "char: impossible" << std::endl 
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
	}
	return ;
}

