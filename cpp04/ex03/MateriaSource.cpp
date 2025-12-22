#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i)
        _templates[i] = other._templates[i] ? other._templates[i]->clone() : 0;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _templates[i];
            _templates[i] = other._templates[i] ? other._templates[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        if (_templates[i])
            delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] == m) {
            std::cout << "MateriaSource already knows " << m->getType() << std::endl;
            return;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] == 0) {
            _templates[i] = m;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn " << m->getType() << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    std::cout << "MateriaSource cannot create materia of type " << type << std::endl;
    return 0;
}
