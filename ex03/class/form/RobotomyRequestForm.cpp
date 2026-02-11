/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:01:29 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 10:13:05 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45, "none")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("Robotomy Request Form", 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm (cpy)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::gradeChecker(executor);
	std::cout << "* GRRRRRRRR BRRRRRRR GRRRGRR BZZZZZZZZZZZZ *" << std::endl;

	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed, " << this->getTarget() << " couldn't robotomized." << std::endl;
}
