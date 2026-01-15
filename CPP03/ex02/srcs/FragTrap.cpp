/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 13:44:20 by cmetee-b         ###   ########.fr       */
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

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << other.name << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called for " << other.name << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_pts = other.hit_pts;
        this->energy_pts = other.energy_pts;
        this->attackdamage = other.attackdamage;
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
