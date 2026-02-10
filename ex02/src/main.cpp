/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:02:24 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 13:56:08 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	AForm *ppfJean;
	try
	{
		ppfJean = new PresidentialPardonForm("Jean");

		Bureaucrat bob("Bob", 5);
		bob.signForm(*ppfJean);
		bob.executeForm(*ppfJean);

		std::cout << std::endl;
		Bureaucrat ann("Ann", 25);
		ann.signForm(*ppfJean);
		ann.executeForm(*ppfJean);

		std::cout << std::endl;
		Bureaucrat jim("Jim", 26);
		jim.signForm(*ppfJean);
		jim.executeForm(*ppfJean);
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
	
	delete ppfJean;
	
	return (0);
}