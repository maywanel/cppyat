#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;
        b1.incrementGrade(10);
        std::cout << "After increment: " << b1 << std::endl;
        b1.decrementGrade(20);
        std::cout << "After decrement: " << b1 << std::endl;
        b1.incrementGrade(100);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b2("Bob", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}