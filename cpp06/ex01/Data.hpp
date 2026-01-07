#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data {
    private:
        int data_number;
        std::string data_string;
    public:
        Data();
        Data(int n, std::string c);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
        int getDataNumber() const;
        std::string getDataString() const;
};

#endif