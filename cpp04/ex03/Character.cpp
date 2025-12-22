#include "Character.hpp"

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    _unequip_count = 395;
    for (int i = 0; i < 400; ++i)
        _unequip_materia[i] = 0;
}

Character::Character(const Character& other) : _name(other._name), _unequip_count(other._unequip_count) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
    for (int i = 0; i < _unequip_count; ++i)
        _unequip_materia[i] = other._unequip_materia[i] ? other._unequip_materia[i]->clone() : 0;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        _unequip_count = other._unequip_count;
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
            _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
        }
        for (int i = 0; i < _unequip_count; ++i) {
            delete _unequip_materia[i];
            _unequip_materia[i] = other._unequip_materia[i] ? other._unequip_materia[i]->clone() : 0;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
      if (_inventory[i])
        delete _inventory[i];
    for (int i = 0; i < _unequip_count; ++i)
      if (_unequip_materia[i])
        delete _unequip_materia[i];
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == m) {
            std::cout << "Materia is already equipped!" << std::endl;
            return;
        }
        if (_inventory[i] == 0) {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
    delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || _inventory[idx] == 0) {
        std::cout << "Invalid index or no materia to unequip at index " << idx << std::endl;
        return;
    }
    if (_unequip_count >= 400) {
        std::cout << "Unequip storage is full, cannot unequip " << _inventory[idx]->getType() << std::endl;
        return;
    }
    _unequip_materia[_unequip_count++] = _inventory[idx];
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || _inventory[idx] == 0) {
        std::cout << "Invalid index or no materia to use at index " << idx << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}

