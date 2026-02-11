/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:29:07 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 10:42:09 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(const std::string& name, int to_sign, int to_exec, const std::string& target);
		AForm(const AForm& cpy);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		const std::string&	getTarget() const;
		int					getGradeToExec() const;

		class GradeException : public std::exception
		{};
		class GradeTooHighException : public GradeException
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public GradeException
		{
			public:
				virtual const char* what() const throw();
		};

		void			beSigned(const Bureaucrat& b);
		void			gradeChecker(const Bureaucrat& b) const;
		virtual void	execute(const Bureaucrat& executor) const = 0;

	private:
		const std::string	m_name;
		const std::string	m_target;
		bool				m_isSigned;
		const int			m_gradeToSign;
		const int			m_gradeToExec;
		AForm&	operator=(const AForm& cpy);
};

#endif
