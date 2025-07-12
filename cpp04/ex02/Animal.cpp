#include "Animal.hpp"

// Animal_A class implementation
Animal_A::Animal_A() : type("Animal_A") {
    std::cout << "Animal_A constructor called" << std::endl;
}

Animal_A::Animal_A(const Animal_A& other) : type(other.type) {
    std::cout << "Animal_A copy constructor called" << std::endl;
}

Animal_A::~Animal_A() {
    std::cout << "Animal_A destructor called" << std::endl;
}

Animal_A& Animal_A::operator=(const Animal_A& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal_A assignment operator called" << std::endl;
    }
    return *this;
}

std::string Animal_A::getType() const {
    return type;
}

// Dog class implementation
Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal_A(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;  
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal_A::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        std::cout << "Dog assignment operator called" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}

// Cat class implementation
Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal_A(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;  
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal_A::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        std::cout << "Cat assignment operator called" << std::endl;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}
// WrongAnimal class implementation
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}   
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "WrongAnimal assignment operator called" << std::endl;
    }
    return *this;
}
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}
std::string WrongAnimal::getType() const {
    return type;
}
