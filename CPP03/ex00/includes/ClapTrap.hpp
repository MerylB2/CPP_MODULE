/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:49 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/14 17:36:23 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
    private :
        std::string name;
        unsigned int hit_pts;
        unsigned int energy_pts;
        unsigned int attackdamage;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& newClap);
        ClapTrap &operator=(const ClapTrap &other_Clap);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

