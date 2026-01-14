/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/14 14:36:02 by cmetee-b         ###   ########.fr       */
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
    this->value = intValue << this->fractionalBits;                 // Convert int to fixed-point representation
}

Fixed::Fixed(const float floatValue)
{
    this->value = roundf(floatValue * (1 << this->fractionalBits)); // Convert float to fixed-point representation
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

// Conversion methods
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->value) / (1 << this->fractionalBits);   //ϵ, telle que 1 + ϵ > 1 ; soit ε = 1 / 2^8 = 1 / 256 = 0.00390625 -> ϵ = 1 / (1 << fractionalBits)
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
    if (other.value != 0) {
        result.setRawBits((this->value << this->fractionalBits) / other.value);
    } else {
        std::cerr << "Error: Division by zero!" << std::endl;
        //result.setRawBits(0);
    }
    return result;
}

Fixed &Fixed::operator++() //prefix increment
{
    this->value++;           // Increment the current object's value
    return *this;            // Return the current object by reference
}

Fixed Fixed::operator++(int) // postfix increment
{
    Fixed temp(*this);       // Create a copy of the current object
    this->value++;           // Increment the current object's value
    return temp;
}

Fixed &Fixed::operator--()    // prefix decrement
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)    // postfix decrement
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
