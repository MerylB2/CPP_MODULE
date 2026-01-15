/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 15:41:08 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->name = "FragTrap";
    this->hit_pts = 100;
    this->energy_pts = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap default constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap parameterized constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& newFrag) : ClapTrap(newFrag)
{
    std::cout << "FragTrap copy constructor called for " << newFrag.name << std::endl;
    *this = newFrag;
}

FragTrap &FragTrap::operator=(const FragTrap &other_Frag)
{
    std::cout << "FragTrap copy assignment operator called for " << other_Frag.name << std::endl;
    if (this != &other_Frag)
    {
        this->name = other_Frag.name;
        this->hit_pts = other_Frag.hit_pts;
        this->energy_pts = other_Frag.energy_pts;
        this->attackdamage = other_Frag.attackdamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl;
}
