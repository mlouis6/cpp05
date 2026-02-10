/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:29:01 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 11:23:21 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : m_name(""), m_isSigned(false), m_gradeToSign(1), m_gradeToExec(1)
{
	if (m_gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string& name, int to_sign, int to_exec) :
	m_name(name), m_isSigned(false), m_gradeToSign(to_sign), m_gradeToExec(to_exec)
{
	if (m_gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& cpy) : 
	m_name(cpy.m_name), m_isSigned(cpy.m_isSigned), m_gradeToSign(cpy.m_gradeToSign), m_gradeToExec(cpy.m_gradeToExec)
{
	if (m_gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{

}

const std::string&	Form::getName() const
{
	return (m_name);
}

bool	Form::getIsSigned() const
{
	return (m_isSigned);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (m_gradeToSign < b.getGrade())
	{
		throw Form::GradeTooLowException();
	}
	m_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}
