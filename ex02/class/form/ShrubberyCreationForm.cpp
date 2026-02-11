/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:01:09 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 10:05:22 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

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
	AForm::execute(executor);

	std::ofstream	ofile((this->getTarget() + "_shrubbery").c_str());
	if (!ofile.good())
	{
		std::cout << "Error\nCouldn't create file" << std::endl;
		return ;
	}
	ofile << "          &&& &&  & &&\n";
	ofile << "      && &\\/&\\|& ()|/ @, &&\n";
	ofile << "      &\\/(/&/&||/& /_/)_&/_&\n";
	ofile << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
	ofile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	ofile << "&&   && & &| &| /& & % ()& /&&\n";
	ofile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	ofile << "     &&     \\|||\n";
	ofile << "             |||\n";
	ofile << "             |||\n";
	ofile << "             |||\n";
	ofile << "       , -=-~  .-^- _\n";
}
