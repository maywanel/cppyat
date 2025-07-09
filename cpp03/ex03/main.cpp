#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Testing DiamondTrap Creation ===" << std::endl;
    DiamondTrap diamond("DT-001");
    
    std::cout << "\n=== DiamondTrap Status ===" << std::endl;
    std::cout << diamond.getName() << " - HP: " << diamond.getHitPoints() 
              << ", EP: " << diamond.getEnergyPoints() 
              << ", AD: " << diamond.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Testing whoAmI() function ===" << std::endl;
    diamond.whoAmI();
    
    std::cout << "\n=== Testing DiamondTrap Attack (Should use ScavTrap's attack) ===" << std::endl;
    diamond.attack("Enemy");
    
    std::cout << "\n=== Testing Inherited Special Abilities ===" << std::endl;
    std::cout << "GuardGate (from ScavTrap):" << std::endl;
    diamond.guardGate();
    
    std::cout << "HighFivesGuys (from FragTrap):" << std::endl;
    diamond.highFivesGuys();
    
    std::cout << "\n=== Testing DiamondTrap vs Others ===" << std::endl;
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");
    FragTrap frag("Frag");
    
    std::cout << "\nDiamondTrap stats - HP: " << diamond.getHitPoints() 
              << ", EP: " << diamond.getEnergyPoints() 
              << ", AD: " << diamond.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats - HP: " << scav.getHitPoints() 
              << ", EP: " << scav.getEnergyPoints() 
              << ", AD: " << scav.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap stats - HP: " << frag.getHitPoints() 
              << ", EP: " << frag.getEnergyPoints() 
              << ", AD: " << frag.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Testing DiamondTrap Combat ===" << std::endl;
    DiamondTrap fighter("Fighter");
    
    // Should have FragTrap's damage (30) and ScavTrap's energy (50)
    fighter.attack("Target");
    fighter.takeDamage(20);
    fighter.beRepaired(10);
    
    std::cout << "\nFighter after combat - HP: " << fighter.getHitPoints() 
              << ", EP: " << fighter.getEnergyPoints() << std::endl;
    
    std::cout << "\n=== Testing DiamondTrap Copy Constructor ===" << std::endl;
    DiamondTrap diamond2(diamond);
    diamond2.whoAmI();
    
    std::cout << "\n=== Testing DiamondTrap Assignment Operator ===" << std::endl;
    DiamondTrap diamond3("Temp");
    diamond3 = diamond;
    diamond3.whoAmI();
    
    std::cout << "\n=== Testing Construction/Destruction Chaining ===" << std::endl;
    {
        std::cout << "Creating DiamondTrap in scope:" << std::endl;
        DiamondTrap temp("Temporary");
        temp.whoAmI();
        std::cout << "DiamondTrap will be destroyed when leaving scope:" << std::endl;
    }
    std::cout << "DiamondTrap destroyed!" << std::endl;
    
    std::cout << "\n=== Testing All Types Together ===" << std::endl;
    {
        ClapTrap basic("Basic");
        ScavTrap guard("Guard");
        FragTrap berserker("Berserker");
        DiamondTrap hybrid("Hybrid");
        
        std::cout << "\nAll performing attacks:" << std::endl;
        basic.attack("Target");      // ClapTrap attack
        guard.attack("Target");      // ScavTrap attack
        berserker.attack("Target");  // ClapTrap attack (FragTrap doesn't override)
        hybrid.attack("Target");     // ScavTrap attack (DiamondTrap uses ScavTrap's)
        
        std::cout << "\nAll performing special abilities:" << std::endl;
        guard.guardGate();
        berserker.highFivesGuys();
        hybrid.guardGate();
        hybrid.highFivesGuys();
        hybrid.whoAmI();
        
        std::cout << "\nDestruction order will be reverse of creation:" << std::endl;
    }
    
    std::cout << "\n=== All remaining objects will be destroyed ===" << std::endl;
    return 0;
}