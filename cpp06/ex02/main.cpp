#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int class_number = rand() % 4;
	switch (class_number) {
	case 0:
		std::cout << "Generated: A" << std::endl;
		return (new A());
	case 1:
		std::cout << "Generated: B" << std::endl;
		return (new B());
	case 2:
		std::cout << "Generated: C" << std::endl;
		return (new C());
	default:
		return (NULL);
	}
}

void identify(Base* p) {
	std::cout << "Identify (pointer): ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown/NULL" << std::endl;
}

void identify(Base& p) {
	std::cout << "Identify (reference): ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast&) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast&) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast&) {
				std::cout << "Unknown/bad_cast" << std::endl;
			}
		}
	}
}

int main(void) {
	srand(time(NULL));

	std::cout << "--- Test 1: Random Generation Loop ---" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << "Test " << i + 1 << ":" << std::endl;
		Base *base = generate();
		if (base == NULL) {
			std::cout << "Generation failed!" << std::endl;
			continue;
		}
		identify(base);
		identify(*base);
		delete base;
		std::cout << "--------------------------------------" << std::endl;
	}
	std::cout << "\n--- Test 2: NULL Pointer ---" << std::endl;
	identify(NULL);
	return (0);
}
