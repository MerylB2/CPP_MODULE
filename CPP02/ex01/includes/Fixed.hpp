/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:57 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/14 14:09:46 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    
    int getRawBits() const;
    void setRawBits(int const raw);
    
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);  // Overload of the insertion operator

/**** Note : "operator<<" c'est la surcharge de l'opérateur d'insertion pour pouvoir utiliser std::cout avec ta classe :
ex :
  Fixed a(42.5f);
  std::cout << a << std::endl;  // affiche la valeur de a directement
  Sans cette surcharge, "std::cout << a" ne compilerait pas car C++ ne sait pas comment afficher un objet Fixed.
  La fonction operator<< convertit l'objet Fixed en une représentation lisible (ici en float) pour l'affichage.
  
****/