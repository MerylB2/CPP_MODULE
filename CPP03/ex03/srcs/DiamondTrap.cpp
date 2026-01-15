/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:24:58 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 17:59:04 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Avec heritage virtuel, on doit appeler ClapTrap() explicitement
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->name = "DiamondTrap";
    ClapTrap::name = this->name + "_clap_name";  // ClapTrap::name est different
    this->hit_pts = 100;        // de FragTrap
    this->energy_pts = 50;      // de ScavTrap
    this->attackdamage = 30;    // de FragTrap
    std::cout << "DiamondTrap default constructor called for " << this->name << std::endl;
}

// ClapTrap recoit name + "_clap_name" comme nom
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->name = name;          // DiamondTrap::name garde le nom original
    this->hit_pts = 100;        // de FragTrap
    this->energy_pts = 50;      // de ScavTrap
    this->attackdamage = 30;    // de FragTrap
    std::cout << "DiamondTrap parameterized constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& newDiamond) : ClapTrap(newDiamond), ScavTrap(newDiamond), FragTrap(newDiamond)
{
    std::cout << "DiamondTrap copy constructor called for " << newDiamond.name << std::endl;
    *this = newDiamond;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other_Diamond)
{
    std::cout << "DiamondTrap copy assignment operator called for " << other_Diamond.name << std::endl;
    if (this != &other_Diamond)
    {
        this->name = other_Diamond.name;
        ClapTrap::name = other_Diamond.ClapTrap::name;
        this->hit_pts = other_Diamond.hit_pts;
        this->energy_pts = other_Diamond.energy_pts;
        this->attackdamage = other_Diamond.attackdamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

// Appelle et tilise attack de ScavTrap
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

// Affiche les deux noms pour montrer la difference
void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
