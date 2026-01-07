#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class B : public Base {
    private:
        std::string info;
    public:
        B();
        B(const B& other);
        B& operator=(const B& other);
        ~B();
        std::string getInfo() const;
};
#endif