#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    std::cout << "=== Basic functionality test ===" << std::endl;
    // const A_Animal* meta = new A_Animal();
    const A_Animal* j = new Dog();
    const A_Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    // meta->makeSound();
    
    // delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Array of Animals test ===" << std::endl;
    const int arraySize = 6;
    A_Animal* animals[arraySize];
    
    // Fill half with Dogs, half with Cats
    for (int idx = 0; idx < arraySize; idx++) {
        if (idx < arraySize / 2) {
            animals[idx] = new Dog();
        } else {
            animals[idx] = new Cat();
        }
    }
    
    std::cout << "\n=== Making sounds ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\n=== Deleting animals ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        delete animals[idx];
    }
    
    std::cout << "\n=== Deep copy test ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I love bones!");
    originalDog.getBrain()->setIdea(1, "Chase cats!");
    
    std::cout << "\nOriginal dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;
    
    Dog copiedDog = originalDog;
    copiedDog.getBrain()->setIdea(0, "I love treats!");
    
    std::cout << "\nAfter copying and modifying copy:" << std::endl;
    std::cout << "Original Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    if (originalDog.getBrain()->getIdea(0) != copiedDog.getBrain()->getIdea(0)) {
        std::cout << "✓ Deep copy successful!" << std::endl;
    } else {
        std::cout << "✗ Shallow copy detected!" << std::endl;
    }
    
    return 0;
}