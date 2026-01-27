#pragma once

#include <map>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <iostream>

class BitcoinExchange {
    private:
        std::map<std::string, double> exchangeRates;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool isLeapYear(int year) const;
        int getDaysInMonth(int month, int year) const;
        bool isValidDate(const std::string& date) const;
        void loadData(const std::string& filename);
        double getExchangeRate(const std::string& date) const;
        void run(const std::string& filename);
};
