#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("CT-001");
    std::cout << "\n=== ClapTrap Status ===" << std::endl;
    std::cout << clap.getName() << " - HP: " << clap.getHitPoints() 
              << ", EP: " << clap.getEnergyPoints() 
              << ", AD: " << clap.getAttackDamage() << std::endl;
    std::cout << "\n=== ClapTrap Actions ===" << std::endl;
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    std::cout << "\n=== Testing ScavTrap Creation ===" << std::endl;
    ScavTrap scav("ST-001");
    std::cout << "\n=== ScavTrap Status ===" << std::endl;
    std::cout << scav.getName() << " - HP: " << scav.getHitPoints() 
              << ", EP: " << scav.getEnergyPoints() 
              << ", AD: " << scav.getAttackDamage() << std::endl;
    std::cout << "\n=== ScavTrap Actions ===" << std::endl;
    scav.attack("Big Enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    std::cout << "\n=== ScavTrap Special Ability ===" << std::endl;
    scav.guardGate();
    std::cout << "\n=== Testing ScavTrap vs ClapTrap Combat ===" << std::endl;
    ScavTrap warrior("Warrior");
    ClapTrap weakling("Weakling");
    std::cout << "\nWarrior attacks Weakling:" << std::endl;
    warrior.attack("Weakling");
    weakling.takeDamage(20);
    std::cout << "\nWeakling tries to fight back:" << std::endl;
    weakling.attack("Warrior");
    warrior.takeDamage(0);
    std::cout << "\n=== Testing ScavTrap Copy Constructor ===" << std::endl;
    ScavTrap scav2(scav);
    scav2.guardGate();
    std::cout << "\n=== Testing ScavTrap Assignment Operator ===" << std::endl;
    ScavTrap scav3("Temp");
    scav3 = scav;
    scav3.guardGate();
    std::cout << "\n=== Testing Construction/Destruction Chaining ===" << std::endl;
    {
        std::cout << "Creating ScavTrap in scope:" << std::endl;
        ScavTrap temp("Temporary");
        std::cout << "ScavTrap will be destroyed when leaving scope:" << std::endl;
    }
    std::cout << "ScavTrap destroyed!" << std::endl;
    std::cout << "\n=== Testing ScavTrap Endurance ===" << std::endl;
    ScavTrap tank("Tank");
    for (int i = 0; i < 5; i++) {
        tank.attack("Target");
        if (i % 2 == 0) {
            tank.beRepaired(5);
        }
    }
    std::cout << "\nTank status - HP: " << tank.getHitPoints() 
              << ", EP: " << tank.getEnergyPoints() << std::endl;   
    std::cout << "\n=== All objects will be destroyed ===" << std::endl;
    return 0;
}