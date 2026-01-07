#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//base class implementations
Base::Base() {}
Base::Base(const Base& other) {
    (void)other;
}
Base& Base::operator=(const Base& other) {
    (void)other;
    return (*this);
}
Base::~Base() {}

//A class implementations
A::A() : info("Class A instance") {}
A::A(const A& other) : Base(other), info(other.getInfo()) {}
A& A::operator=(const A& other) {
    if (this != &other) {
        Base::operator=(other);
        info = other.getInfo();
    }
    return (*this);
}
A::~A() {}
std::string A::getInfo() const {
    return info;
}

//B class implementations
B::B() : info("Class B instance") {}
B::B(const B& other) : Base(other), info(other.getInfo()) {}
B& B::operator=(const B& other) {
    if (this != &other) {
        Base::operator=(other);
        info = other.getInfo();
    }
    return (*this);
}
B::~B() {}
std::string B::getInfo() const {
    return info;
}

//C class implementations
C::C() : info("Class C instance") {}
C::C(const C& other) : Base(other), info(other.getInfo()) {}
C& C::operator=(const C& other) {
    if (this != &other) {
        Base::operator=(other);
        info = other.getInfo();
    }
    return (*this);
}
C::~C() {}
std::string C::getInfo() const {
    return info;
}
