/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 15:35:13 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/ClapTrap.hpp"

// "virtual" evite la duplication de ClapTrap dans DiamondTrap
// HP: 100, Energy: 100, Attack: 30
class FragTrap : virtual public ClapTrap
{
    public:
        // Orthodox Canonical Form
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& newFrag);
        FragTrap &operator=(const FragTrap &other_Frag);
        ~FragTrap();

        void highFivesGuys(void);  // Methode speciale de FragTrap
};
