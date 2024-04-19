#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BOLD	"\e[1m"
#define DIM		"\e[2m"
#define ITAL	"\e[3m"
#define ULINE	"\e[4m"

#define	YELLOW	"\e[38;2;217;255;0m"
#define	PINK	"\e[38;2;255;0;89m"
#define PURPLE	"\e[38;2;255;0;217m"
#define	GREEN	"\e[38;2;89;255;0m"
#define	RED		"\e[38;2;255;0;0m"
#define BLUE	"\e[38;2;0;233;255m"
#define	LBLUE1	"\e[38;2;191;240;255m"
#define LBLUE2	"\e[38;2;168;205;255m"
#define ORANGE	"\e[38;2;255;166;0m"

#define RESET	"\e[0m"

#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
	public :
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		virtual ~Bureaucrat(void);

		Bureaucrat	 &	operator=(Bureaucrat const & src);
		
		const std::string	getName() const;
		int					getGrade() const;

		void	incrementeGrade(void);
		void	decrementeGrade(void);

		void	signForm(Form &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		static const int	_lowestGrade = 150;
		static const int	_highestGrade = 1;
	private :
		const std::string	_name;
		int					_grade;//has to be between 1 and 150

};

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & src);

#endif
