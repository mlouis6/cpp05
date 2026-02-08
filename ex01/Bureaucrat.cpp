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
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("unnamed"), m_grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int	grade) : m_name(name)
{
	try
	{
		m_grade = grade;
		if (m_grade < 1)
			throw Bureaucrat::GradeTooLowException();
		else if (m_grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		m_grade = 1;
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		m_grade = 150;
		std::cout << e.what();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : m_name(cpy.m_name), m_grade(cpy.m_grade)
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& cpy)
{
	static_cast<void>(cpy);
	return (*this);
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

Bureaucrat&	Bureaucrat::operator++()
{
	try
	{
		m_grade -= 1;
		if (m_grade < 1)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		m_grade = 1;
		std::cout << e.what();
	}
	return (*this);
}

Bureaucrat&	Bureaucrat::operator--()
{
	try
	{
		m_grade += 1;
		if (m_grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		m_grade = 150;
		std::cout << e.what();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

