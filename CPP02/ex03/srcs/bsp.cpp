/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/14 13:23:21 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"

static Fixed area(Point const a, Point const b, Point const c) // Helper function to calculate the area of a triangle
{
    Fixed result = (a.getX() * (b.getY() - c.getY()) + 
                   b.getX() * (c.getY() - a.getY()) + 
                   c.getX() * (a.getY() - b.getY())) / Fixed(2); 
    
    return (result < Fixed(0)) ? result * Fixed(-1) : result;   // Return absolute value
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);                              // Area of the whole triangle ABC
    Fixed areaPBC = area(point, b, c);                          // Area of triangle PBC
    Fixed areaAPC = area(a, point, c);                          // Area of triangle APC
    Fixed areaABP = area(a, b, point);                          // Area of triangle ABP
    
    // Check if point is on the edge of the triangle   
    
    if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
        return false;
    
    return (areaABC == (areaPBC + areaAPC + areaABP));
}
