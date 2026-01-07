#include "Data.hpp"

Data::Data() {
    data_number = 0;
    data_string = "";
}
Data::Data (int n, std::string s) : data_number(n), data_string(s) {}
Data::Data(const Data& other) : data_number(other.getDataNumber()), data_string(other.getDataString()) {}
Data& Data::operator=(const Data& other) {
    	if (this != &other) {}
	return (*this);
}
Data::~Data() {}

int Data::getDataNumber() const {
    return data_number;
}

std::string Data::getDataString() const {
    return data_string;
}
