#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();
    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;
    return 0;
}