#include "../include/iter.hpp"

int main(void)
{
	std::cout << "-- Test with an int array --" << std::endl;
	int tab[4] = {2, 5, 42, 9};
	iter(tab, 4, fctIncremente);

	for (int i = 0; i < 4; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
/*	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;*/
	return 0;
}