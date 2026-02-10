/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:05:06 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/10 16:45:47 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include <exception>

class Intern
{
	public:
		Intern();
		Intern(const Intern& cpy);
		Intern& operator=(const Intern& cpy);
		~Intern();
		AForm*	makeForm(const std::string& name, const std::string& target);

		class NoFormException : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

	private:
		static std::string forms[3];
};

#endif
