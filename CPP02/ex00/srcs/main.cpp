/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:27:03 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/12 16:44:25 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;									// Default constructor	
	Fixed b( a );								// Copy constructor
	Fixed c;									// Default constructor
	
	c = b;										// Copy assignment operator
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;  
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}
