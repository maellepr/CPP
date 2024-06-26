#include "../include/Span.hpp"

Span::Span(void)
{
	return ;
}

Span::Span(unsigned int n): N(n)  
{
	return ;
}

Span::Span(Span const & src)
{
	if (this != &src)
		this->N = src.N;
}

Span::~Span(void)
{
	return ;
}

Span & Span::operator=(Span const & src)
{
	if (this != &src)
		this->N = src.N;
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (this->tab.size() >= N)
		throw Span::ArrayIsFull();
	else 
		this->tab.push_back(nb);
	return ;
}

void	Span::addNumberRange(std::vector<int> vecToAdd)
{
	std::vector<int>::iterator begin = vecToAdd.begin();
	std::vector<int>::iterator end = vecToAdd.end();
	
	if (this->tab.size() == N)
		throw Span::ArrayIsFull();
	else if ((this->tab.size() + vecToAdd.size()) > N)
	{
		int	availableSize = N - this->tab.size();
		this->tab.insert(this->tab.end(), begin, begin + availableSize);
	}
	else
		this->tab.insert(this->tab.end(), begin, end);
	return ;
}

int	Span::shortestSpan(void)
{
	if (tab.size() > 1)
	{
		std::sort(tab.begin(), tab.end());
		int	distMin = tab[1] - tab[0];
		for (unsigned int i = 0; i < (tab.size() - 1); i++)
		{
			if (tab[i + 1] - tab[i] < distMin)
				distMin = tab[i + 1] - tab[i];
		}
		return (distMin);
	}
	throw Span::NoDistanceFound();
}

int	Span::longestSpan(void)
{
	if (tab.size() > 1)
	{
		std::sort(tab.begin(), tab.end());
		int distMax = tab[tab.size() - 1] - tab[0];
		return (distMax);
	}
	throw Span::NoDistanceFound();
}

/* Exceptions */
const char *Span::ArrayIsFull::what(void) const throw()
{
	return ("No more room in the span ! Can't add any more numbers");
}

const char *Span::NoDistanceFound::what(void) const throw()
{
	return ("No distance was find : there's either only one number saved or none");
}

void	Span::PrintSpan(void)
{
	std::cout << "Span : ";
	for (unsigned int i = 0; i < tab.size(); i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
}