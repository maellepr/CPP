
#include "Fixed.hpp"
#include "Point.hpp"


void	print(Point const a, Point const b, Point const c, Point const point, bool expect)
{
	if (expect)
		std::cout << "EXPECTED: point INSIDE abc triangle" << std::endl;
	else
		std::cout << "EXPECTED: point OUTSIDE or on the sides of abc triangle" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "RESULT: point INSIDE" << std::endl;
	else
		std::cout << "RESULT: point OUTSIDE" << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	bool		expect;
	{
		Point const	a(0, 0);
		Point const	b(6, 0);
		Point const	c(0, 6);
		{
			Point const point(1.5f, 1.5f);
			expect = true;
			print(a, b, c, point, expect);
		}
		{
			Point const point(a);
			expect = false;
			print(a, b, c, point, expect);
		}
		{
			Point const point(10.0f, 1.5f);
			expect = false;
			print(a, b, c, point, expect);
		}
		{
			Point const point(4.5f, 0.5f);
			expect = true;
			print(a, b, c, point, expect);
		}
	}
	{
		Point const a(-5.44f, 0.29f);
		Point const b(2.62f, 2.95f);
		Point const c(1.0f, -1.45f);
		{
			Point const point;
			expect = true;
			print(a, b, c, point, expect);
		}
		{
			Point const point(c);
			expect = false;
			print(a, b, c, point, expect);
		}
		{
			Point const point(-5.45f, 0.29f);
			expect = false;
			print(a, b, c, point, expect);
		}
		{
			Point const point(3.5f, 1.5f);
			expect = false;
			print(a, b, c, point, expect);
		}
		{
			Point const point(1.5f, 1.5f);
			expect = true;
			print(a, b, c, point, expect);
		}
	}
	return 0;
}
