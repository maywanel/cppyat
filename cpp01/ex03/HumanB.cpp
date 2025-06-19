#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name) {}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " is unarmed" << std::endl;
    }
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}
