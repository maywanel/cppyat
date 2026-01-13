#include <Array.hpp>
#include <Array.tpp>

int main(int, char**)
{
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.getSize(); i++) {
        intArray[i] = i * 10;
    }

    Array<int> copyArray = intArray;
    for (unsigned int i = 0; i < copyArray.getSize(); i++) {
        std::cout << "Element " << i << ": " << copyArray[i] << std::endl;
    }

    try {
        std::cout << intArray[10] << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}