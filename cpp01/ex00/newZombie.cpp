#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(const std::string& name) {
    Zombie* zombie = new Zombie(name);
    return zombie;
}