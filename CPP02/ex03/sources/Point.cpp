#include "Point.hpp"

/**** Default constructor ****/
Point::Point(void): _x(0), _y(0)
{
	return ;
}

/**** Constructor ****/
Point::Point(float const x1, float const y1): _x(x1), _y(y1)
{
	return ;
}

/**** Copy constructor ****/
Point::Point (Point const & src) : _x(src.getX()), _y(src.getY())
{
	return ;
}

/**** Destructor ****/
Point::~Point(void)
{
	return ;
}

Point &	Point::operator=(Point const & src)
{
	// if (this != &src)
	(void)src;
	return (*this);
}

/**** Getters ****/
Fixed const	& Point::getX(void) const
{
	return (this->_x);
}

Fixed const	& Point::getY(void) const
{
	return (this->_y);
}