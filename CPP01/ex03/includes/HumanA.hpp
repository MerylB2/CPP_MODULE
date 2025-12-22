/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:59:14 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 19:15:39 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
    std::string name;
    Weapon& weapon; // Reference - always has a weapon, cannot change
    
public:
    HumanA(const std::string& name, Weapon& weapon); // Takes weapon in constructor
    ~HumanA();
    
    void attack() const; // Attack function
};

#endif