#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie() {}

void Zombie::announce() const {
    std::cout << "Zombie " << name << " is announcing itself!" << std::endl;
}
