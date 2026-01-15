/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:37:05 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 16:28:49 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructeur par defaut avec liste d'initialisation
ClapTrap::ClapTrap() : name("ClapTrap"), hit_pts(10), energy_pts(10), attackdamage(0)
{
    std::cout << "Default constructor called for " << this->name << std::endl;
}

// Constructeur avec parametre
ClapTrap::ClapTrap(const std::string& clap) : name(clap), hit_pts(10), energy_pts(10), attackdamage(0)
{
    std::cout << "Parameterized constructor called for " << this->name << std::endl;
}

// Constructeur de copie
ClapTrap::ClapTrap(const ClapTrap& newClap)
{
    std::cout << "Copy constructor called for " << newClap.name << std::endl;
    *this = newClap;  // Utilise operator= pour copier
}

// Operateur d'affectation
ClapTrap &ClapTrap ::operator=(const ClapTrap &other_Clap)
{
    std::cout << "Copy assignment operator called for " << other_Clap.name << std::endl;
    if (this != &other_Clap)  // Evite l'auto-affectation (a = a)
    {
        this->name = other_Clap.name;
        this->hit_pts = other_Clap.hit_pts;
        this->energy_pts = other_Clap.energy_pts;
        this->attackdamage = other_Clap.attackdamage;
    }
    return *this;  // Permet le chainage (a = b = c)
}

// Destructeur
ClapTrap:: ~ClapTrap ()
{
    std::cout << "Destructor called for " << this->name << std::endl;
}

// Attaque : coute 1 energie
void ClapTrap::attack(const std::string& target)
{
    if (this->energy_pts > 0 && this->hit_pts > 0)
    {
        this->energy_pts--;
        std::cout << this->name << " attacks " << target << " , causing " << this->attackdamage << " points of damage! (Energy left: " << this->energy_pts << ")" << std::endl;
    }
    else
        std::cout << "No energy left!" << std::endl;
}

// Prend des degats
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_pts <= amount)
    {
        this->hit_pts = 0;
        std::cout << this->name << " has been destroyed! " << std::endl;
    }
    else
    {
        this->hit_pts -= amount;
        std::cout << this->name << " takes " << amount << " damage! (HP left: " << this->hit_pts << ", Energy left: " << this->energy_pts << ")" << std::endl;
    }
}

// Reparation : coute 1 energie, recupere des HP
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_pts > 0 && this->hit_pts > 0)
    {
        this->hit_pts += amount;
        this->energy_pts--;
        std::cout << this->name << " repairs itself, regain " << amount << " hit points! (HP: " << this->hit_pts << ", Energy left: " << this->energy_pts << ")" << std::endl;
    }
    else
        std::cout << "Cannot repair: no energy or no HP left!" << std::endl;
}

