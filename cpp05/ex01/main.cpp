#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Form1", 50, 30);
        
        std::cout << "Bureaucrat name: " << bob.getName() << std::endl;
        std::cout << "Form name: " << form1.getName() << std::endl;
        
        bob.signForm(form1);
        std::cout << "Form signed status: " << form1.isSigned() << std::endl;
        
        Bureaucrat alice("Alice", 100);
        Form form2("Form2", 50, 25);
        
        std::cout << "Bureaucrat name: " << alice.getName() << std::endl;
        alice.signForm(form2);
        std::cout << "Form signed status: " << form2.isSigned() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}