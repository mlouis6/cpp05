/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:03:48 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 16:46:47 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string Intern::forms[3] = {"shrubbery creation",
								"robotomy request",
								"presidential pardon"};

Intern::Intern()
{

}

Intern::Intern(const Intern& cpy)
{
	static_cast<void>(cpy);
}

Intern& Intern::operator=(const Intern& cpy)
{
	static_cast<void>(cpy);
	return (*this);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm*	form;
	int		i = 0;

	while (i < 3)
	{
		if (name == forms[i])
			break ;
		++i;
	}
	try
	{
		switch (i)
		{
			case 0:
			{
				form = new ShrubberyCreationForm(target);
				break ;
			}
			case 1:
			{
				form = new RobotomyRequestForm(target);
				break ;
			}
			case 2:
			{
				form = new PresidentialPardonForm(target);
				break ;
			}
			default:
				throw Intern::NoFormException();
		}
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (form);
}

Intern::~Intern()
{

}

const char* Intern::NoFormException::what() const throw()
{
	return ("The demanded form doesn't exist");
}

