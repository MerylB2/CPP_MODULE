/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 19:32:50 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
    Fixed result = (a.getX() * (b.getY() - c.getY()) + 
                   b.getX() * (c.getY() - a.getY()) + 
                   c.getX() * (a.getY() - b.getY())) / Fixed(2);
    
    return (result < Fixed(0)) ? result * Fixed(-1) : result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);
    Fixed areaPBC = area(point, b, c);
    Fixed areaAPC = area(a, point, c);
    Fixed areaABP = area(a, b, point);
    
    if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
        return false;
    
    return (areaABC == (areaPBC + areaAPC + areaABP));
}