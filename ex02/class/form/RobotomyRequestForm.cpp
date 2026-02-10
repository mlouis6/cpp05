/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:01:29 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 13:57:11 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
	if (this->getGradeToExec() < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	
}
