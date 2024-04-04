
#include "Fixed.hpp"

int main( void )
{
	// Fixed a(2);
	// Fixed b(4);
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a / b << std::endl;
	//renvoie 1 quand c'est vrai 0 quand c'est faux
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	Fixed c(2);
	Fixed d(4);
	Fixed e(4);

	Fixed f((float)7.25);

	Fixed const g (Fixed(10) * Fixed(2));
	Fixed const h (200);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// std::cout << std::endl << "OPERATEURS DE COMPARAISON" << std::endl;
	// std::cout << "Testing (c > d) <=> (2 > 4)" << std::endl;
	// std::cout <<  "0 <- expected result" << std::endl;
	// std::cout << (c > d) << std::endl;
	// std::cout << "Testing (c < d) <=> (2 < 4)" << std::endl;
	// std::cout <<  "1 <- expected result" << std::endl;
	// std::cout << (c < d) << std::endl;
	// std::cout << "Testing (c >= d) <=> (2 >= 4)" << std::endl;
	// std::cout <<  "0 <- expected result" << std::endl;
	// std::cout << (c >= d) << std::endl;
	// std::cout << "Testing (e <= d) <=> (4 <= 4)" << std::endl;
	// std::cout << "1 <- expected result" << std::endl;
	// std::cout << (e <= d) << std::endl;
	// std::cout << "Testing (c == d) <=> (2 == 4)" << std::endl;
	// std::cout <<  "0 <- expected result" << std::endl;
	// std::cout << (c == d) << std::endl;
	// std::cout << "Testing (e == d) <=> (e == 4)" << std::endl;
	// std::cout <<  "1 <- expected result" << std::endl;
	// std::cout << (e == d) << std::endl;
	// std::cout << "Testing (c != d) <=> (2 != 4)"<< std::endl; 
	// std::cout <<  "1 <- expected result" << std::endl;
	// std::cout << (c != d) << std::endl;
	// std::cout << "Testing (e != d) <=> (4 != 4)" << std::endl;
	// std::cout <<  "0 <- expected result" << std::endl;
	// std::cout << (e != d) << std::endl;
	// std::cout << std::endl << "OPERATEURS D'ARITHMETIQUES" << std::endl;
	// std::cout << "Testing (c + d) <=> (2 + 4)" << std::endl;
	// std::cout <<  "6 <- expected result" << std::endl;
	// std::cout << (c + d) << std::endl;
	// std::cout << "Testing (f - c) <=> (7.25 - 2)" << std::endl;
	// std::cout <<  "5.25 <- expected result" << std::endl;
	// std::cout << (f - c) << std::endl;
	// std::cout << "Testing (c * f) <=> (2 * 7.25)" << std::endl;
	// std::cout <<  "14.5 <- expected result" << std::endl;
	// std::cout << (c * f) << std::endl;
	// std::cout << "Testing (f / c) <=> (7.25 / 2)" << std::endl;
	// std::cout <<  "3.625 <- expected result" << std::endl;
	// std::cout << (f / c) << std::endl;
	// std::cout << std::endl << "OPERATEURS D'INCREMENTATION/DECREMENTATION (+ ou - 0.00390625)" << std::endl;
	// std::cout << "f = " << f << std::endl;
	// std::cout << "--f = " << --f << std::endl;
	// std::cout << "f = " << f << std::endl;
	// std::cout << "f-- = " << f-- << std::endl;
	// std::cout << "f = " << f << std::endl;
	// std::cout << std::endl << "FONCTIONS MIN ET MAX" << std::endl;
	// std::cout << "Testing min(c, e) <=> (2, 4)" << std::endl;
	// std::cout <<  "2 <- expected result" << std::endl;	
	// std::cout << Fixed::min( c, e ) << std::endl;
	// std::cout << "Testing max(c, e) <=> (2, 4)" << std::endl;
	// std::cout <<  "4 <- expected result" << std::endl;	
	// std::cout << Fixed::max( c, e ) << std::endl;
	// std::cout << std::endl << "FONCTIONS MIN ET MAX STATIQUES" << std::endl;
	// std::cout << "Testing min(h, g) <=> (200, 20)" << std::endl;
	// std::cout <<  "20 <- expected result" << std::endl;	
	// std::cout << Fixed::min( h, g ) << std::endl;
	// std::cout << "Testing max(h, g) <=> (200, 20)" << std::endl;
	// std::cout <<  "200 <- expected result" << std::endl;	
	// std::cout << Fixed::max( h, g ) << std::endl;
	return 0;
}
