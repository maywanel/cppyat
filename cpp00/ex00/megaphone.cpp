/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:35:47 by moel-mes          #+#    #+#             */
/*   Updated: 2025/11/01 03:35:53 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

char convertToUpper(char c) {
    return std::toupper(c);
}

int main (int ac, char *av[]) {
  std::string loud;
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  else {
    for (int i = 1; i < ac; i++)
      loud.append(av[i]);
    for (std::size_t j = 0; j < loud.size(); ++j)
      loud[j] = convertToUpper(loud[j]);
    std::cout << loud << "\n";
  }
  return 0;
}
