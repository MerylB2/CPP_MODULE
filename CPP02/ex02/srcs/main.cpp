/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/11 20:30:35 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "----- Additional Tests -----" << std::endl;
    Fixed x(3.5f);
    Fixed y(2);
    std::cout << "x: " << x << ", y: " << y << std::endl;
    std::cout << "x + y: " << (x + y) << std::endl;
    std::cout << "x - y: " << (x - y) << std::endl;
    std::cout << "x * y: " << (x * y) << std::endl;
    std::cout << "x / y: " << (x / y) << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl; 
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    return 0;
}
