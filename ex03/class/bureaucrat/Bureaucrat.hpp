/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:03:18 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 13:34:01 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iosfwd>
# include <exception>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int	grade);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		Bureaucrat&			operator++();
		Bureaucrat&			operator--();
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

		void	signForm(AForm& form) const;
		void	executeForm(const AForm& form) const;

	private:
		const std::string	m_name;
		int					m_grade;
		Bureaucrat&	operator=(const Bureaucrat& cpy);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b); 

#endif
