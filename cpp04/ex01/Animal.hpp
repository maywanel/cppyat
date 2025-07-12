#ifndef ANIMAL_HPP
#define ANIMAL_HPP 
#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
};

class Dog : public Animal {
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();
        Dog& operator=(const Dog& other);
        void makeSound() const;
        Brain* getBrain() const;
};

class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);
        void makeSound() const;
        Brain* getBrain() const;
};

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif
