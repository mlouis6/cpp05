/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:02:24 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 16:00:47 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

int	main()
{

	/** PRESIDENTIAL PARDON FORM */
	std::cout << "*** PRESIDENTIAL PARDON FORM ***" << std::endl;
	AForm *ppfBillie;
	AForm *ppfJean;
	AForm *ppfKing;
	try
	{
		ppfBillie = new PresidentialPardonForm("Billie");

		Bureaucrat bob("Bob", 5);
		bob.signForm(*ppfBillie);
		bob.executeForm(*ppfBillie);

		ppfJean = new PresidentialPardonForm("Jean");
		std::cout << std::endl;
		Bureaucrat ann("Ann", 25);
		ann.signForm(*ppfJean);
		ann.executeForm(*ppfJean);
		bob.executeForm(*ppfJean);

		ppfKing = new PresidentialPardonForm("King");
		std::cout << std::endl;
		Bureaucrat jim("Jim", 26);
		jim.signForm(*ppfKing);
		jim.executeForm(*ppfKing);
		bob.executeForm(*ppfKing);
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
	
	delete ppfBillie;
	delete ppfJean;
	delete ppfKing;

	/** ROBOTOMY REQUEST FORM */
	std::srand(time(0));
	std::cout << "\n\n*** ROBOTOMY REQUEST FORM ***" << std::endl;
	try
	{
		RobotomyRequestForm rrfBillie("Billie");

		Bureaucrat bob("Bob", 5);
		bob.signForm(rrfBillie);
		bob.executeForm(rrfBillie);

		RobotomyRequestForm rrfJean("Jean");
		std::cout << std::endl;
		Bureaucrat ann("Ann", 63);
		ann.signForm(rrfJean);
		ann.executeForm(rrfJean);
		bob.executeForm(rrfJean);

		RobotomyRequestForm rrfKing("King");
		std::cout << std::endl;
		Bureaucrat jim("Jim", 75);
		jim.signForm(rrfKing);
		jim.executeForm(rrfKing);
		bob.executeForm(rrfKing);
	}
	catch (const AForm::GradeException& e)
	{
		std::cout << "Error form: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeException& e)
	{
		std::cout << "Error bureaucrat: " << e.what() << std::endl;
	}

	/** SHRUBBERY CREATION FORM */
	std::cout << "\n\n*** SHRUBBERY CREATION FORM ***" << std::endl;
	try
	{
		ShrubberyCreationForm scfBillie("Billie");

		Bureaucrat bob("Bob", 5);
		bob.signForm(scfBillie);
		bob.executeForm(scfBillie);

		ShrubberyCreationForm scfJean("Jean");
		std::cout << std::endl;
		Bureaucrat ann("Ann", 140);
		ann.signForm(scfJean);
		ann.executeForm(scfJean);
		bob.executeForm(scfJean);

		ShrubberyCreationForm scfKing("King");
		std::cout << std::endl;
		Bureaucrat jim("Jim", 150);
		jim.signForm(scfKing);
		jim.executeForm(scfKing);
		bob.executeForm(scfKing);
	}
	catch (const AForm::GradeException& e)
	{
		std::cout << "Error form: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeException& e)
	{
		std::cout << "Error bureaucrat: " << e.what() << std::endl;
	}
	
	return (0);
}