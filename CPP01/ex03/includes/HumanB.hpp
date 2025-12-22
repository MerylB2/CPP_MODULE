/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:59:55 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 19:00:21 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:
    std::string name;
    Weapon* weapon; // Pointer - may not have a weapon, can be set later
    
public:
    HumanB(const std::string& name); // Does not take weapon in constructor
    ~HumanB();
    
    void setWeapon(Weapon& weapon); // Sets weapon after construction
    void attack() const;            // Attack function
};

#endif