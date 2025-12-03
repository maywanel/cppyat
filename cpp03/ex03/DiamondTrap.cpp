#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
    _attackDamage = FragTrap::_attackDamage;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    std::cout << "Diamond Default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    _attackDamage = FragTrap::_attackDamage;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    _attackDamage = other._attackDamage;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
        _attackDamage = other._attackDamage;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed.\n";
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
    std::cout << "DiamondTrap name: " << _name << "\n";
    std::cout << "ClapTrap name: " << ClapTrap::_name << "\n";
}
