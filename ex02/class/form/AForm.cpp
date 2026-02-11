/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:29:01 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 10:14:43 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : m_name("no name form"), m_target("none"), m_isSigned(false), m_gradeToSign(1), m_gradeToExec(1)
{
	if (m_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string& name, int to_sign, int to_exec, const std::string& target) :
	m_name(name),
	m_target(target),
	m_isSigned(false),
	m_gradeToSign(to_sign),
	m_gradeToExec(to_exec)
{
	if (m_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& cpy) : 
	m_name(cpy.m_name),
	m_target(cpy.m_target),
	m_isSigned(cpy.m_isSigned),
	m_gradeToSign(cpy.m_gradeToSign),
	m_gradeToExec(cpy.m_gradeToExec)
{
	if (m_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (m_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{

}

const std::string&	AForm::getName() const
{
	return (m_name);
}

bool	AForm::getIsSigned() const
{
	return (m_isSigned);
}

const std::string&	AForm::getTarget() const
{
	return (m_target);
}

int	AForm::getGradeToExec() const
{
	return (m_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (m_gradeToSign < b.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	m_isSigned = true;
}

void	AForm::gradeChecker(const Bureaucrat& b) const
{
	if (m_gradeToExec < b.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}
