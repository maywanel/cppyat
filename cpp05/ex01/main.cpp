#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Form1", 50, 30);
        
        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;
        
        bob.signForm(form1);
        std::cout << form1 << std::endl;
        
        Bureaucrat alice("Alice", 100);
        Form form2("Form2", 50, 25);
        
        std::cout << alice << std::endl;
        alice.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}