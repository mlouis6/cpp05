/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:03:22 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/05 16:17:23 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("unnamed"), m_grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int	grade = 150) : m_name(name)
{
	//TODO: execption
	m_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : Bureaucrat(cpy)
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& cpy)
{
	static_cast<void>(cpy);
}

Bureaucrat::~Bureaucrat()
{

}

const std::string&	Bureaucrat::getName() const
{
	return(m_name);
}

int	Bureaucrat::getGrade() const
{
	return(m_grade);
}

Bureaucrat&	Bureaucrat::operator++() const
{
	if ()
	this->m_grade -= 1;
}

Bureaucrat&	Bureaucrat::operator--() const
{
	
}

// Bureaucrat::GradeTooHighException

// Bureaucrat::GradeTooLowException

