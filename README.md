# C++ Modules (cpp00 - cpp09) By moel-mes

This repository contains solutions for C++ programming exercises covering fundamental to advanced concepts in C++. The project is organized into 10 modules (cpp00 through cpp09), each focusing on specific C++ programming concepts.

## Author
- **moel-mes** (moel-mes@student.1337.ma)

## Project Overview

This project is a comprehensive C++ learning journey covering topics from basic syntax to advanced STL usage and algorithms. Each module builds upon the previous ones, introducing new concepts and best practices in C++ programming.

## Modules Description

### Module 00 - Basics and I/O
Introduction to C++ basics, namespaces, classes, and I/O operations.

**Exercises:**
- **ex00 - Megaphone**: A program that converts input strings to uppercase
- **ex01 - PhoneBook**: A simple phonebook application with Contact and PhoneBook classes
- **ex02 - Account**: Account management system implementation

### Module 01 - Memory Allocation and References
Focus on memory allocation, pointers, references, and the switch statement.

**Exercises:**
- **ex00 - Zombie**: Basic class implementation with heap and stack allocation
- **ex01 - Zombie Horde**: Creating multiple zombie instances
- **ex02 - Brain**: String reference exercises
- **ex03 - Violence**: Weapon class with references
- **ex04 - Sed**: String replacement utility
- **ex05 - Harl**: Log filtering system
- **ex06 - Harl Filter**: Extended log filtering with levels

### Module 02 - Ad-hoc Polymorphism and Fixed-Point Numbers
Introduction to operator overloading and orthodox canonical form.

**Exercises:**
- **ex00 - Fixed**: Basic fixed-point number class
- **ex01 - Fixed (Extended)**: Fixed-point with conversion constructors
- **ex02 - Fixed (Operators)**: Arithmetic and comparison operators
- **ex03 - BSP**: Binary Space Partitioning with Point class

### Module 03 - Inheritance
Understanding inheritance, access specifiers, and class hierarchies.

**Exercises:**
- **ex00 - ClapTrap**: Base robot class
- **ex01 - ScavTrap**: Derived class with special abilities
- **ex02 - FragTrap**: Another derived class variant
- **ex03 - DiamondTrap**: Multiple inheritance and the diamond problem

### Module 04 - Subtype Polymorphism and Interfaces
Virtual functions, abstract classes, and interfaces.

**Exercises:**
- **ex00 - Animal**: Polymorphism with Animal, Dog, Cat classes
- **ex01 - Brain**: Deep copy and memory management with Brain class
- **ex02 - Abstract Class**: Making Animal an abstract class
- **ex03 - Materia**: Interface implementation with Ice, Cure, and Character classes

### Module 05 - Exceptions
Exception handling, try-catch blocks, and creating custom exceptions.

**Exercises:**
- **ex00 - Bureaucrat**: Basic exception handling
- **ex01 - Form**: Form class with exceptions
- **ex02 - Forms**: Concrete form implementations
- **ex03 - Intern**: Form creation factory

### Module 06 - Casts
Different types of C++ casts and type conversion.

**Exercises:**
- **ex00 - ScalarConverter**: Converting between scalar types
- **ex01 - Serialization**: Pointer serialization/deserialization
- **ex02 - Identify**: Runtime type identification

### Module 07 - Templates
Function templates, class templates, and template specialization.

**Exercises:**
- **ex00 - Templates**: Basic function templates (swap, min, max)
- **ex01 - Iter**: Template function for array iteration
- **ex02 - Array**: Template class for dynamic arrays

### Module 08 - STL Containers
Introduction to Standard Template Library containers and iterators.

**Exercises:**
- **ex00 - Easyfind**: Finding elements in containers
- **ex01 - Span**: Managing a collection of numbers
- **ex02 - Stack**: Mutant stack implementation

### Module 09 - STL Algorithms
Advanced STL usage with containers and algorithms.

**Exercises:**
- **ex00 - BitcoinExchange**: Bitcoin price calculator using historical data
- **ex01 - RPN**: Reverse Polish Notation calculator with stack
- **ex02 - PmergeMe**: Merge-insert sort implementation with vector and deque

## Compilation

Each exercise comes with its own Makefile. To compile an exercise:

```bash
cd cpp[module]/ex[number]
make
```

Example:
```bash
cd cpp00/ex00
make
./megaphone
```

### Compilation Flags

All exercises are compiled with the following flags:
- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors
- `-std=c++98`: Use C++98 standard

## Usage

Each exercise produces an executable that can be run directly. Some exercises require command-line arguments:

### Examples:

**Megaphone (cpp00/ex00):**
```bash
./megaphone hello world
# Output: HELLOWORLD (arguments are concatenated without spaces)
```

**PhoneBook (cpp00/ex01):**
```bash
./phonebook
# Interactive program: use ADD, SEARCH, and EXIT commands
```

**Bitcoin Exchange (cpp09/ex00):**
```bash
./btc input.txt
# Calculates Bitcoin values based on historical exchange rates
```

**RPN Calculator (cpp09/ex01):**
```bash
./RPN "3 4 + 2 *"
# Output: 14
```

**PmergeMe (cpp09/ex02):**
```bash
./PmergeMe 3 5 9 7 4
# Sorts numbers and displays timing for different containers
```

## Project Structure

```
cppyat/
├── cpp00/          # Module 00: Basics
│   ├── ex00/       # Megaphone
│   ├── ex01/       # PhoneBook
│   └── ex02/       # Account
├── cpp01/          # Module 01: Memory & References
│   ├── ex00/       # Zombie
│   ├── ex01/       # Zombie Horde
│   ├── ex02/       # Brain
│   ├── ex03/       # Violence
│   ├── ex04/       # Sed replacement
│   ├── ex05/       # Harl
│   └── ex06/       # Harl Filter
├── cpp02/          # Module 02: Polymorphism
│   ├── ex00/       # Fixed
│   ├── ex01/       # Fixed extended
│   ├── ex02/       # Fixed operators
│   └── ex03/       # BSP
├── cpp03/          # Module 03: Inheritance
│   ├── ex00/       # ClapTrap
│   ├── ex01/       # ScavTrap
│   ├── ex02/       # FragTrap
│   └── ex03/       # DiamondTrap
├── cpp04/          # Module 04: Subtype Polymorphism
│   ├── ex00/       # Animal
│   ├── ex01/       # Brain
│   ├── ex02/       # Abstract
│   └── ex03/       # Materia
├── cpp05/          # Module 05: Exceptions
│   ├── ex00/       # Bureaucrat
│   ├── ex01/       # Form
│   ├── ex02/       # Forms
│   └── ex03/       # Intern
├── cpp06/          # Module 06: Casts
│   ├── ex00/       # ScalarConverter
│   ├── ex01/       # Serialization
│   └── ex02/       # Identify
├── cpp07/          # Module 07: Templates
│   ├── ex00/       # Function templates
│   ├── ex01/       # Iter
│   └── ex02/       # Array
├── cpp08/          # Module 08: STL Containers
│   ├── ex00/       # Easyfind
│   ├── ex01/       # Span
│   └── ex02/       # Stack
└── cpp09/          # Module 09: STL Algorithms
    ├── ex00/       # BitcoinExchange
    ├── ex01/       # RPN
    └── ex02/       # PmergeMe
```

## Key Concepts Covered

### Object-Oriented Programming
- Classes and objects
- Encapsulation and data hiding
- Constructors and destructors
- Copy constructors and assignment operators
- Orthodox Canonical Form

### Memory Management
- Stack vs Heap allocation
- Memory leaks prevention
- Deep vs Shallow copy
- Resource management (RAII)

### Polymorphism
- Function overloading
- Operator overloading
- Virtual functions
- Abstract classes and interfaces
- Multiple inheritance

### Advanced C++ Features
- Templates (function and class)
- Exception handling
- Type casting (static_cast, dynamic_cast, reinterpret_cast, const_cast)
- STL containers (vector, stack, deque, map)
- STL algorithms
- Iterators

## Standards and Best Practices

- **C++98 Standard**: All code follows C++98 standard
- **Coding Style**: Follows 42 School norm
- **Memory Safety**: No memory leaks (verified with valgrind)
- **Error Handling**: Proper exception handling where appropriate
- **Code Organization**: Separate header (.hpp) and implementation (.cpp) files (note: template code is typically kept in headers)

## Building All Modules

To compile all exercises in a specific module (example for cpp00):

```bash
# Navigate to each exercise in cpp00 and compile
for dir in cpp00/ex*/; do
    (cd "$dir" && make)
done
```

To compile all exercises in all modules:

```bash
# Compile all exercises across all modules
for module in cpp*/; do
    for ex in "$module"ex*/; do
        (cd "$ex" && make)
    done
done
```

## Cleaning

Each Makefile includes clean targets:

```bash
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Rebuild from scratch
```

## Notes

- All exercises are designed to run on Linux/Unix systems
- Some exercises may require specific input files (provided in their directories)
- Memory leaks are strictly forbidden and should be checked with tools like valgrind
- Code follows strict compilation flags to ensure quality and standards compliance

## License

This project is part of the 42 School curriculum and is meant for educational purposes.
