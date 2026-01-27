#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }

    BitcoinExchange bitcoinExchange;
    try {
        bitcoinExchange.loadData("data.csv");
        bitcoinExchange.run(argv[1]);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    return 0;
}
