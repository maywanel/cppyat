#include "Harl.hpp"
#include <limits>

int main() {
    Harl harl;
    std::string level;

    while (true) {
        std::cout << "Enter a complaint level (DEBUG, INFO, WARNING, ERROR) or EXIT to exit the program: ";
        if (!std::getline(std::cin, level))
        {
            std::cout << "\nInput stream closed. Exiting." << std::endl;
            break;
        }
	if (level == "")
            continue;
        if (level == "EXIT") {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        harl.complain(level);
    }
    return 0;
} 
