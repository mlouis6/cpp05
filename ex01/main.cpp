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
	Bureaucrat b;
	std::cout << b << std::endl;
	--b;
	std::cout << b << std::endl;
	++b;
	std::cout << b << std::endl;

	std::cout << std::endl;

	Bureaucrat b2("Bob", 1);
	std::cout << b2 << std::endl;
	++b2;
	std::cout << b2 << std::endl;
	--b2;
	std::cout << b2 << std::endl;

	
	
	return (0);
}