/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:29:07 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/08 15:32:46 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form
{
	public:
		Form(); //no signed
		
		Form(const Form& cpy);
		Form&	operator=(const Form& cpy);
		~Form();

	private:
		const std::string	m_name;
		bool				m_is_signed;
		const int			m_grade_to_sign;
		const int			m_grade_to_exec;
};

#endif
