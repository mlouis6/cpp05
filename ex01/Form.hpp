/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:29:07 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 11:23:21 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string& name, int to_sign, int to_exec);
		Form(const Form& cpy);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;

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

		void	beSigned(const Bureaucrat& b);

	private:
		const std::string	m_name;
		bool				m_isSigned;
		const int			m_gradeToSign;
		const int			m_gradeToExec;
		Form&	operator=(const Form& cpy);
};

#endif
