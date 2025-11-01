/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:10:03 by moel-mes          #+#    #+#             */
/*   Updated: 2025/10/05 17:10:03 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
  public:
	  Bureaucrat(void);
	  Bureaucrat(std::string name, int grade);
	  ~Bureaucrat();
	  Bureaucrat(const Bureaucrat& original);
	  Bureaucrat& operator=(const Bureaucrat& toCopy);
    std::string		getName() const;
  	int				    getGrade() const;
  	void			    incrementGrade(int toInc);
  	void			    decrementGrade(int toDec);
  private:
    const std::string _name;
    int _grade;
};

#endif
