#include <iostream>
#include <cstdlib>
#include <algorithm>

char convertToUpper(char c) {
    return std::toupper(static_cast<unsigned char>(c));
}

int main (int ac, char *av[]) {
  std::string loud;
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  else {
    for (int i = 1; i < ac; i++)
      loud.append(av[i]);
    std::transform(loud.begin(), loud.end(), loud.begin(), convertToUpper);
    std::cout << loud << "\n";
  }
  return 0;
}
