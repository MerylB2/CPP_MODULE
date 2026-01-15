/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 02:22:52 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 15:37:32 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/ClapTrap.hpp"

// "virtual" evite la duplication de ClapTrap dans DiamondTrap
// HP: 100, Energy: 50, Attack: 20
class ScavTrap : virtual public ClapTrap
{
    public:
        // Orthodox Canonical Form
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& newScav);
        ScavTrap &operator=(const ScavTrap &other_Scav);
        ~ScavTrap();

        void attack(const std::string& target);  // Redefinit attack() de ClapTrap
        void guardGate();                        // Methode speciale de ScavTrap
};
