/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 02:24:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 02:24:01 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->name = "ScavTrap";
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap default constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap parameterized constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for " << other.name << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called for " << other.name << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_pts = other.hit_pts;
        this->energy_pts = other.energy_pts;
        this->attackdamage = other.attackdamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_pts > 0 && this->hit_pts > 0)
    {
        this->energy_pts--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage! (Energy left: " << this->energy_pts << ")" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
