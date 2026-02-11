/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:02:24 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 10:15:08 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

int	main()
{
	Intern	someIntern;
	
	try
	{
		AForm	*ppfBillie = someIntern.makeForm("presidential pardon", "Billie");

		Bureaucrat bob("Bob", 5);
		bob.signForm(*ppfBillie);
		bob.executeForm(*ppfBillie);
		delete ppfBillie;

		std::srand(time(0));
		AForm	*rrfJean = someIntern.makeForm("robotomy request", "Jean");
		std::cout << std::endl;
		Bureaucrat ann("Ann", 25);
		ann.signForm(*rrfJean);
		ann.executeForm(*rrfJean);
		delete rrfJean;

		AForm	*scfKing = someIntern.makeForm("shrubbery creation", "King");
		std::cout << std::endl;
		Bureaucrat jim("Jim", 26);
		jim.signForm(*scfKing);
		jim.executeForm(*scfKing);
		delete scfKing;

		AForm	*badForm = someIntern.makeForm("bad bad bad", "Form");
		std::cout << std::endl;
		Bureaucrat axl("axl", 26);
		axl.signForm(*badForm);
		axl.executeForm(*badForm);
		delete badForm;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	catch (const AForm::GradeException& e)
	{
		std::cout << "Error form: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeException& e)
	{
		std::cout << "Error bureaucrat: " << e.what() << std::endl;
	}
	catch (const Intern::NoFormException& e)
	{
		std::cout << "Error intern: " << e.what() << std::endl;
	}
	
	return (0);
}