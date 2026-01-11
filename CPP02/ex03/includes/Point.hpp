/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 19:32:50 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();
    
    Fixed getX(void) const;
    Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);