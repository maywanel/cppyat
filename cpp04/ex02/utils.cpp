#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// Animal class implementation
A_Animal::A_Animal() : type("Animal") {

    std::cout << "Animal constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

A_Animal::~A_Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assignment operator called" << std::endl;
    }
    return *this;
}

std::string A_Animal::getType() const {
    return type;
}

// Dog class implementation
Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : A_Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;  
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        A_Animal::operator=(other);
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
    return this->brain;
}

// Cat class implementation
Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : A_Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;  
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        A_Animal::operator=(other);
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
    return this->brain;
}

