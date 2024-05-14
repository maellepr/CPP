#include "../include/RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(RPN const & src)
{
	if (this != &src)
		*this = src;
}

RPN::~RPN(void)
{
	return ;
}

RPN & RPN::operator=(RPN const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	RPN::checkError(const std::string line) const
{
	std::stack<int> stack;
	
	if (!line.size())
	{
		// std::cout << "1";
		throw Error();
	}
	if (line[0] < '0' || line[1] > '9')
	{
		// std::cout << "2";
		throw Error();
	}
	int	i = 1;
	int nb = 0;

	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
		{
			// std::cout << "2";
			throw Error();
		}
		if ((line[i] >= '0' && line[i] <= '9') && nb >= 0)
		{
			nb++;
			i++;
		}
		else if ((line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') && nb >= 1)
		{
			i++;
			nb--;
		}
		else
		{
			// std::cout << "4";
			throw Error();
		}

	}
	if ((line[i - 1] != '+' && line[i - 1] != '-' && line[i - 1] != '*' && line[i - 1] != '/') || nb != 0)
	{
		// std::cout << "5";
		throw Error();
	}
	return ;
}

void	RPN::doCalcul(const std::string line) const
{
	std::stack<int> data;
	int value;
	long top;
	long before_top;
	int result;

	value = line[0] - 48;
	data.push(value);
	for (unsigned int i = 1; i < line.size(); i++)
	{
		if (line[i] == ' ')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			value = line[i] - 48;
			// std::cout << "'" << value << "'";
			data.push(value);
		}
		else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
		{		
			top = data.top();
			data.pop();
			before_top = data.top();
			data.pop();
			// std::cout << "top = " << top << " ope = " << line[i] << " before top = " << before_top << std::endl;
			if (line[i] == '*' && (before_top * top <= 2147483647) && (before_top * top >= -2147483648))
			{
				// std::cout << before_top * top << "**\n";
				result = before_top * top;
			}
			else if (line[i] == '/' && top != 0 && (before_top / top <= 2147483647) && (before_top / top >= -2147483648))
			{
				// std::cout << "here\n";
				result = before_top / top;
			}
			else if (line[i] == '+' && (before_top + top <= 2147483647) && (before_top + top >= -2147483648))
			{
				// std::cout << "++\n";
				result = before_top + top;
			}
			else if (line[i] == '-' && (before_top - top <= 2147483647) && (before_top - top >= -2147483648))
			{
				// std::cout << "--\n";
				result = before_top - top;
			}
			else
				throw Error();
			data.push(result);
		}
	}
	std::cout << data.top() << std::endl;
}