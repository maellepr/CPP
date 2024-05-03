#include "../include/Span.hpp"

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.PrintSpan();

	std::cout << sp.shortestSpan() << std::endl;
	sp.PrintSpan();

	std::cout << sp.longestSpan() << std::endl;
	sp.PrintSpan();

	return 0;
}