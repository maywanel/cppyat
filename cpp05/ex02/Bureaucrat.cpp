#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy) {
    if (this != &toCopy) {
        this->_grade = toCopy._grade;
    }
    return *this;
}
std::string Bureaucrat::getName() const {
    return _name;
}
int Bureaucrat::getGrade() const {
    return _grade;
}
void Bureaucrat::incrementGrade(int toInc) {
    if (_grade - toInc < 1)
        throw GradeTooHighException();
    _grade -= toInc;
}

void Bureaucrat::decrementGrade(int toDec) {
    if (_grade + toDec > 150)
        throw GradeTooLowException();
    _grade += toDec;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
