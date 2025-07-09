#include "FragTrap.hpp"

int main() {
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("CT-001");
    
    std::cout << "\n=== ClapTrap Status ===" << std::endl;
    std::cout << clap.getName() << " - HP: " << clap.getHitPoints() 
              << ", EP: " << clap.getEnergyPoints() 
              << ", AD: " << clap.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Testing ScavTrap Creation ===" << std::endl;
    ScavTrap scav("ST-001");
    
    std::cout << "\n=== ScavTrap Status ===" << std::endl;
    std::cout << scav.getName() << " - HP: " << scav.getHitPoints() 
              << ", EP: " << scav.getEnergyPoints() 
              << ", AD: " << scav.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Testing FragTrap Creation ===" << std::endl;
    FragTrap frag("FT-001");
    
    std::cout << "\n=== FragTrap Status ===" << std::endl;
    std::cout << frag.getName() << " - HP: " << frag.getHitPoints() 
              << ", EP: " << frag.getEnergyPoints() 
              << ", AD: " << frag.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Comparing Attack Styles ===" << std::endl;
    std::cout << "ClapTrap attack:" << std::endl;
    clap.attack("Enemy");
    
    std::cout << "ScavTrap attack:" << std::endl;
    scav.attack("Enemy");
    
    std::cout << "FragTrap attack:" << std::endl;
    frag.attack("Enemy");
    
    std::cout << "\n=== Special Abilities ===" << std::endl;
    std::cout << "ScavTrap special ability:" << std::endl;
    scav.guardGate();
    
    std::cout << "FragTrap special ability:" << std::endl;
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing FragTrap Combat ===" << std::endl;
    FragTrap warrior("Destroyer");
    ClapTrap victim("Victim");
    
    std::cout << "\nDestroyer attacks Victim:" << std::endl;
    warrior.attack("Victim");
    victim.takeDamage(30); // FragTrap deals 30 damage - should kill ClapTrap
    
    std::cout << "\n=== Testing FragTrap Endurance ===" << std::endl;
    FragTrap tank("Tank");
    
    // FragTrap has 100 energy points, so it can do more actions
    std::cout << "Tank performing multiple actions:" << std::endl;
    for (int i = 0; i < 10; i++) {
        tank.attack("Target");
        if (i % 3 == 0) {
            tank.beRepaired(5);
        }
    }
    
    std::cout << "\nTank status - HP: " << tank.getHitPoints() 
              << ", EP: " << tank.getEnergyPoints() << std::endl;
    
    std::cout << "\n=== Testing FragTrap vs ScavTrap ===" << std::endl;
    FragTrap fragFighter("FragFighter");
    ScavTrap scavFighter("ScavFighter");
    
    std::cout << "\nFragFighter (HP:100, EP:100, AD:30) vs ScavFighter (HP:100, EP:50, AD:20)" << std::endl;
    
    fragFighter.attack("ScavFighter");
    scavFighter.takeDamage(30);
    
    scavFighter.attack("FragFighter");
    fragFighter.takeDamage(20);
    
    std::cout << "\nAfter one exchange:" << std::endl;
    std::cout << "FragFighter HP: " << fragFighter.getHitPoints() << std::endl;
    std::cout << "ScavFighter HP: " << scavFighter.getHitPoints() << std::endl;
    
    std::cout << "\n=== Testing FragTrap Copy Constructor ===" << std::endl;
    FragTrap frag2(frag);
    frag2.highFivesGuys();
    
    std::cout << "\n=== Testing FragTrap Assignment Operator ===" << std::endl;
    FragTrap frag3("Temp");
    frag3 = frag;
    frag3.highFivesGuys();
    
    std::cout << "\n=== Testing Construction/Destruction Chaining ===" << std::endl;
    {
        std::cout << "Creating FragTrap in scope:" << std::endl;
        FragTrap temp("Temporary");
        temp.highFivesGuys();
        std::cout << "FragTrap will be destroyed when leaving scope:" << std::endl;
    }
    std::cout << "FragTrap destroyed!" << std::endl;
    
    std::cout << "\n=== Testing All Three Types Together ===" << std::endl;
    {
        ClapTrap basic("Basic");
        ScavTrap guard("Guard");
        FragTrap berserker("Berserker");
        
        std::cout << "\nAll three performing their signature moves:" << std::endl;
        basic.attack("Target");
        guard.guardGate();
        berserker.highFivesGuys();
        
        std::cout << "\nDestruction order will be reverse of creation:" << std::endl;
    }
    
    std::cout << "\n=== All remaining objects will be destroyed ===" << std::endl;
    return 0;
}