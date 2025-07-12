#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria() {}
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif