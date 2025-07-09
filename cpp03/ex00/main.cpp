#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap clap1("ARTHUR");
    ClapTrap clap2("ElPhen");
    std::cout << "\n=== Initial Status ===" << std::endl;
    std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
              << ", EP: " << clap1.getEnergyPoints() 
              << ", AD: " << clap1.getAttackDamage() << std::endl;
    std::cout << "\n=== Testing Attack ===" << std::endl;
    clap1.attack("Enemy");
    clap1.attack("Another Enemy");
    std::cout << "\n=== Testing Take Damage ===" << std::endl;
    clap1.takeDamage(5);
    clap1.takeDamage(3);
    std::cout << "\n=== Testing Repair ===" << std::endl;
    clap1.beRepaired(4);
    std::cout << "\n=== Testing Energy Exhaustion ===" << std::endl;
    for (int i = 0; i < 8; i++)
        clap1.attack("Target");
    std::cout << "\n=== Testing Actions with No Energy ===" << std::endl;
    clap1.attack("Can't attack");
    clap1.beRepaired(10);
    std::cout << "\n=== Testing Death ===" << std::endl;
    clap2.takeDamage(15);
    clap2.attack("Can't attack when dead");
    clap2.beRepaired(5);
    clap2.takeDamage(5);
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    ClapTrap clap3(clap1);
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    ClapTrap clap4("Temp");
    clap4 = clap1;
    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}