#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

#include "Materia.hpp"

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
        AMateria* _unequip_materia[400];
        int _unequip_count;
    public:
        Character(std::string const & name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif