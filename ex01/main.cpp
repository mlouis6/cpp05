/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:02:24 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/08 14:15:21 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat b;
		std::cout << b << std::endl;
		++b;
		std::cout << b << std::endl;
		--b;
		std::cout << b << std::endl;
		--b;
		std::cout << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat b("Bob", 1);
		std::cout << b << std::endl;
		++b;
		std::cout << b << std::endl;
		--b;
		std::cout << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b("Diane", 0);
		std::cout << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Quentin", 151);
		std::cout << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << e.what() << std::endl;
	}
	
	return (0);
}