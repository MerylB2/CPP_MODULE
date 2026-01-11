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
#include "../includes/Point.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== BSP Triangle Test ===" << std::endl;
    
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    
    std::cout << "Triangle: A(0,0), B(5,0), C(2.5,5)" << std::endl;
    
    Point inside(2.5f, 2.0f);
    Point outside(10.0f, 10.0f);
    Point vertex(0.0f, 0.0f);
    Point edge(2.5f, 0.0f);
    
    std::cout << "Point inside (2.5, 2): " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Point outside (10, 10): " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;
    std::cout << "Point on vertex (0, 0): " << (bsp(a, b, c, vertex) ? "True" : "False") << std::endl;
    std::cout << "Point on edge (2.5, 0): " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
    
    std::cout << std::endl << "=== Additional Tests ===" << std::endl;
    
    Point p1(1.0f, 1.0f);
    Point p2(4.0f, 1.0f);
    Point p3(2.5f, 3.0f);
    Point p4(0.5f, 0.5f);
    Point p5(1.5f, 1.5f);
    
    std::cout << "Point (1, 1): " << (bsp(a, b, c, p1) ? "True" : "False") << std::endl;
    std::cout << "Point (4, 1): " << (bsp(a, b, c, p2) ? "True" : "False") << std::endl;
    std::cout << "Point (2.5, 3): " << (bsp(a, b, c, p3) ? "True" : "False") << std::endl;
    std::cout << "Point (0.5, 0.5): " << (bsp(a, b, c, p4) ? "True" : "False") << std::endl;
    std::cout << "Point (1.5, 1.5): " << (bsp(a, b, c, p5) ? "True" : "False") << std::endl;
    
    return 0;
}
