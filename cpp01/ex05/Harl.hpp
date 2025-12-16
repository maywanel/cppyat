#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
    public:
        Harl();
        ~Harl();
        void complain(const std::string level);

    private:
        void debug();
        void info();
        void warning();
        void error();
        void (Harl::*actions[4])(void);
        std::string levels[4];
};

#endif
