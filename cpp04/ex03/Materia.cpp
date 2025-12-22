#include "Materia.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "Using A Materia" << std::endl;
}

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
