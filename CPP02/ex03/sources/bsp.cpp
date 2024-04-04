#include "Point.hpp"
#include <cmath>

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	check1 = c.getY() - a.getY();
	Fixed	check2 = (((b.getY() - a.getY()) * (c.getX() - a.getX())) - (((b.getX() - a.getX()) * (c.getY() - a.getY()))));

	float	check_1 = check1.toFloat();
	float	check_2 = check2.toFloat();

	if (check_1 == 0 || check_2 == 0)
		std::cout << "There's a division by 0 in the algorythme, the final result might be wrong !" << std::endl;
	
	Fixed 	w1 = (a.getX() * (c.getY() - a.getY()) + ((point.getY() - a.getY()) * (c.getX() - a.getX())) - point.getX() * (c.getY() - a.getY())) / (((b.getY() - a.getY()) * (c.getX() - a.getX())) - (((b.getX() - a.getX()) * (c.getY() - a.getY()))));
	Fixed	w2 = (point.getY() - a.getY() - w1 * (b.getY() - a.getY())) / c.getY() - a.getY();

	// std::cout << "w1 = " << w1 << std::endl;
	// std::cout << "w2 = " << w2 << std::endl;

	float	w_1 = w1.toFloat();
	float	w_2 = w2.toFloat();
	
	// std::cout << "w_1 = " << w_1 << std::endl;
	// std::cout << "w_2 = " << w_2 << std::endl;
	
	if (w_1 > 0 && w_2 > 0 && ((w_1 + w_2) < 1))
		return true;
	return false;
}