#include "Serializer.hpp"

int main() {
	Data* data = new Data(42, "42 Heilbronn!");
	uintptr_t serialized = Serializer::serialize(data);
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "serialized: " << serialized << std::endl;
	std::cout << "Deserialized: " << std::endl;
	std::cout << "\tString: " << deserialized->getDataString() << std::endl;
	std::cout << "\tInt: " << deserialized->getDataNumber() << std::endl;
	delete data;
	return 0;
}