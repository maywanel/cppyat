#include "Zombie.hpp"

int main() {
    int N = 6;
    std::string name = "Simo";

    Zombie* horde = zombieHorde(N, name);
    if (horde) {
        for (int i = 0; i < N; ++i)
            horde[i].announce();
        delete[] horde;
    } else {
        std::cout << "Failed to create zombie horde." << std::endl;
    }

    return 0;
}