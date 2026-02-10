/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:01:09 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 13:38:52 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "none")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("Shrubbery Creation Form", 145, 137, target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm (cpy)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getGradeToExec() < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	// std::cout << this->getTarget() << " has been pardoned by President Zaphod Beeblebrox." << std::endl;
}
