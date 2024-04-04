#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	public :
		Fixed(void);
		Fixed (Fixed const & src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);

		Fixed &	operator=(Fixed const & src);

		Fixed	operator>(Fixed const & src) const;
		Fixed	operator<(Fixed const & src) const;
		Fixed	operator>=(Fixed const & src) const;
		Fixed	operator<=(Fixed const & src) const;
		Fixed	operator==(Fixed const & src) const;
		Fixed	operator!=(Fixed const & src) const;

		Fixed	operator+(Fixed const & nb1) const;
		Fixed	operator-(Fixed const & src) const;
		Fixed	operator*(Fixed const & src) const;
		Fixed	operator/(Fixed const & src) const;

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed &nb1, Fixed &nb2);
		static Fixed &			max(Fixed &nb1, Fixed &nb2);
		static Fixed const &	min(Fixed const & nb1, Fixed const & nb2);
		static Fixed const &	max(Fixed const & nb1, Fixed const & nb2);

	private :
		int					_nbFixedPt;
		static const int	_nbBits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & t);

#endif