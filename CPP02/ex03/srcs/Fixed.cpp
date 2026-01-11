/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/09 16:31:03 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int intValue)
{
    this->value = intValue << this->fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    this->value = roundf(floatValue * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->value = other.value;
    return *this;
}

int Fixed::getRawBits() const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->value) / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->value >> this->fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->value - other.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->value * other.value) >> this->fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->value << this->fractionalBits) / other.value);
    return result;
}

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
