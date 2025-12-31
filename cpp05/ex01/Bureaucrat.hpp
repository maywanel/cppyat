#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
 	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& original);
		Bureaucrat& operator=(const Bureaucrat& toCopy);
    	std::string	getName() const;
		int getGrade() const;
		void incrementGrade(int toInc);
		void decrementGrade(int toDec);
		void signForm(Form &form) const;

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
