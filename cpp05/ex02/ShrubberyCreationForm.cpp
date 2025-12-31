#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
    : AForm(original), _target(original._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy) {
    if (this != &toCopy) {
        AForm::operator=(toCopy);
        this->_target = toCopy._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    executeAction();
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;

    outfile.close();
}