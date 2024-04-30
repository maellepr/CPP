#include "../include/iter.hpp"

int main(void)
{
	std::cout << BOLD << "-- Test with an int array --" << RESET << std::endl;
	int tabInt[4] = {2, 5, 42, 9};
	iter(tabInt, 4, fctPrint<const int>);
	std::cout << std::endl;
	iter(tabInt, 4, fctIncremente<int>);
	iter(tabInt, 4, fctPrint<const int>);
	std::cout << std::endl << std::endl;

	std::cout << BOLD << "-- Test with a char array --" << RESET << std::endl;
	char tabChar[5] = {'a', 'b', 'c', 'd'};
	iter(tabChar, 5, fctPrint<const char>);
	std::cout << std::endl;
	iter(tabChar, 5, fctIncremente<char>);
	iter(tabChar, 5, fctPrint<const char>);
	std::cout << std::endl << std::endl;

	std::cout << BOLD << "-- Test with a float array --" << RESET << std::endl;
	float tabFloat[3] = {3.04f, 6.33f, 10.80f};
	iter(tabFloat, 3, fctPrint<const float>);
	std::cout << std::endl;
	iter(tabFloat, 3, fctIncremente<float>);
	iter(tabFloat, 3, fctPrint<const float>);
	std::cout << std::endl << std::endl;

	std::cout << BOLD << "-- Test with empty array --" << RESET << std::endl;
	int tabEmpty[0] = {};
	iter(tabEmpty, 0, fctPrint<const int>);
	iter(tabEmpty, 0, fctIncremente<int>);
	iter(tabEmpty, 0, fctPrint<const int>);
	return 0;
}