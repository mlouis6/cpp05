/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:01:50 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 15:10:24 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5, "no one")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("Presidential Pardon Form", 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm (cpy)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by President Zaphod Beeblebrox." << std::endl;
}

