#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <string>

class Base {
    protected:
        Base();
        Base(const Base& other);
        Base& operator=(const Base& other);
    public:
        virtual ~Base();
};

#endif