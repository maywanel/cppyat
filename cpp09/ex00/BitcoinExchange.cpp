#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        exchangeRates = other.exchangeRates;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::getDaysInMonth(int month, int year) const {
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))  return 29;
    return daysInMonth[month - 1];
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12) return false;
    int daysInMonth = getDaysInMonth(month, year);
    if (day < 1 || day > daysInMonth) return false;
    return true;
}

bool BitcoinExchange::isValidData(const std::string& data) {
    if (data.empty()) return false;
    for (size_t i = 0; i < data.length(); ++i)
        if (!std::isdigit(data[i]) && data[i] != '.' && data[i] != '-') return false;
    return true;
}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            if (line == "date,exchange_rate") continue;
        }
        if (!isValidData(line))
            throw std::runtime_error("Error: invalid data in file.");
        if (!line.empty() && line[line.length() - 1] == '\r') 
            line.erase(line.length() - 1);
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) continue;
        std::string date = trim(line.substr(0, commaPos));
        if (!isValidDate(date)) continue;
        std::string rateStr = trim(line.substr(commaPos + 1));
        char* endPtr;
        double rate = std::strtod(rateStr.c_str(), &endPtr);
        if (rateStr.empty() || *endPtr != '\0')
            throw std::runtime_error("Error: invalid exchange rate in data file.");
        exchangeRates[date] = rate;
    }
    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    if (it != exchangeRates.end() && it->first == date)
        return it->second;
    if (it != exchangeRates.begin()) {
        --it;
        return it->second;
    }
    throw std::runtime_error("Error: bad input => " + date);
}

void BitcoinExchange::run(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (!line.empty() && line[line.length() - 1] == '\r') line.erase(line.length() - 1);
        if (firstLine) {
            firstLine = false;
            if (line == "date | value") continue;
        }
        if (line.empty()) continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << (date.empty() ? line : date) << std::endl;
            continue;
        }

        std::string valueStr = trim(line.substr(pipePos + 1));
        char* end;
        double value = std::strtod(valueStr.c_str(), &end);
        if (valueStr.empty() || *end != '\0') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            double rate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    file.close();
}
