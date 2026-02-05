/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:03:18 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/05 16:07:34 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int	grade);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		Bureaucrat&			operator++() const;
		Bureaucrat&			operator--() const;

		class Exception
		{
			public:

		};

	private:
		const std::string	m_name;
		int					m_grade;
		Bureaucrat&	operator=(const Bureaucrat& cpy);
};

#endif
