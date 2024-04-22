#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;
class Form
{
	public :
		Form(void);
		Form(const std::string name, const int to_sign, const int to_exec);
		Form(Form const & src);
		virtual ~Form(void);

		Form	 &	operator=(Form const & src);
		
		const std::string	getName() const;

		bool				isSigned() const;
		int					getGradeRequiredToSign(void) const;
		int					getGradeRequiredToExecute(void) const;

		void				beSigned(Bureaucrat const &b);

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
		class AlreadySigned : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

	private :
		const std::string	_name;
		bool				_signed;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
};

std::ostream &	operator<<(std::ostream & os, Form const & src);

#endif