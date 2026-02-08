/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:03:22 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/08 14:16:10 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat() : m_name("unnamed"), m_grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int	grade) : m_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : m_name(cpy.m_name), m_grade(cpy.m_grade)
{

}

// Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& cpy)
// {
// 	static_cast<void>(cpy);
// 	return (*this);
// }

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

Bureaucrat&	Bureaucrat::operator++()
{
	if (m_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade -= 1;
	return (*this);
}

Bureaucrat&	Bureaucrat::operator--()
{
	if (m_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade += 1;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
