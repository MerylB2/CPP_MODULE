/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/14 13:45:23 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : x(0), y(0)         // Default constructor initializes x and y to 0
{
}

Point::Point(const float x, const float y) : x(x), y(y) // Parameterized constructor
{
}

Point::Point(const Point &other) : x(other.x), y(other.y) // Copy constructor
{
}

Point &Point::operator=(const Point &other)
{
    (void)other;                       // Assignment operator does nothing as x and y are const
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX(void) const
{
    return this->x;
}

Fixed Point::getY(void) const
{
    return this->y;
}