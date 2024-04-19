#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
	public :
		AForm(void);
		AForm(const std::string name, const int to_sign, const int to_exec);
		AForm(AForm const & src);
		virtual ~AForm(void);

		AForm	 &	operator=(AForm const & src);
		
		const std::string	getName() const;

		bool	isSigned() const;
		int		getGradeRequiredToSign(void) const;
		int		getGradeRequiredToExecute(void) const;
		void	beSigned(Bureaucrat const &b);

		void	execute(Bureaucrat const & executor) const;

		virtual void	doExecution(void) const = 0;

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
		class NotSigned : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

	private :
		const std::string	_name;
		bool				_signed;// not signed at construction
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
};

std::ostream &	operator<<(std::ostream & os, AForm const & src);

#endif