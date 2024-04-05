#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	public :
		Point(void);
		Point(float const x1, float const y1);
		Point (Point const & src);//constructor de recopie
		~Point(void);

		Point &	operator=(Point const & src);
		
		Fixed const	&	getX(void) const;
		Fixed const	&	getY(void) const;

	private :
		Fixed const	_x;
		Fixed const	_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif