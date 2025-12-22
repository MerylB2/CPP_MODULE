/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:58:25 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 19:12:19 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
    std::string type;
    
public:
    Weapon();                                   // Default constructor
    Weapon(const std::string& type);            // Parameterized constructor
    Weapon(const Weapon& other);                // Copy constructor
    Weapon& operator=(const Weapon& other);     // Assignment operator
    ~Weapon();                                  // Destructor
    
    const std::string& getType() const;         // Returns constant reference to type
    void setType(const std::string& type);      // Sets type using new value
};

#endif