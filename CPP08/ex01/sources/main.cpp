#include "../include/Span.hpp"

int main(void)
{
	std::cout << BOLD << "-- Test with a span size 5 (from the subject) --" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.PrintSpan();

	std::cout << "The sortest span in sp : "  << sp.shortestSpan() << std::endl;
	sp.PrintSpan();

	std::cout << "The longest span in sp : " << sp.longestSpan() << std::endl;
	sp.PrintSpan();


	std::cout << BOLD << "\n-- Test with a span size 15000 --" << RESET << std::endl;
	Span sp2 = Span(15000);
	std::vector<int> vec1(10000, 100);
	std::vector<int> vec2(5000, 200);

	try
	{
		sp2.addNumber(vec1);
		std::cout << "vec1 was succesfully add to sp2 !" << std::endl;

		sp2.addNumber(vec2);
		std::cout << "vec2 was succesfully add to sp2 !" << std::endl;

		sp2.addNumber(vec1);
		std::cout << "vec1 was succesfully add to sp2 !" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "The sortest span in sp2 : " << sp2.shortestSpan() << std::endl;
	std::cout << "The longest span in sp2 : " << sp2.longestSpan() << std::endl;

	std::cout << BOLD << "\n-- Test with a empty span --" << RESET << std::endl;
	Span spEmpty = Span(0);
	try
	{
		spEmpty.addNumber(45);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		spEmpty.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		spEmpty.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}