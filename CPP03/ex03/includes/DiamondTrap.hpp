/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:24:28 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 17:20:11 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

// Heritage multiple : DiamondTrap herite de ScavTrap ET FragTrap
// Grace au "virtual" dans ScavTrap/FragTrap, on evite le probleme du diamant
// (ClapTrap n'est pas duplique)
class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;  // Son propre name (different de ClapTrap::name)

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& newDiamond);
        DiamondTrap &operator=(const DiamondTrap &other_Diamond);
        ~DiamondTrap();

        //using ScavTrap::attack;  // Utilise attack() de ScavTrap
        void attack(const std::string& target);
        void whoAmI();           // Affiche les deux noms (DiamondTrap et ClapTrap)
};
