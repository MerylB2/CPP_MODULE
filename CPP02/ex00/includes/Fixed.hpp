/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 19:32:50 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed(); // Default constructor
    ~Fixed(); // Destructor
    Fixed(const Fixed &other); // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    
    int getRawBits() const; // Getter for raw bits
    void setRawBits(int const raw); // Setter for raw bits
    
};

