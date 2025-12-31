#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
        virtual void executeAction() const = 0;
    public:
        AForm(std::string name, int signGrade, int execGrade);
        virtual ~AForm();
        AForm(const AForm& original);
        AForm& operator=(const AForm& toCopy);
        std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};


#endif