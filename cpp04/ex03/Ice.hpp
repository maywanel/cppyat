#ifndef ICE_HPP
#define ICE_HPP

#include "Materia.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif