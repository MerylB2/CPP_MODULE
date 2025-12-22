/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:53:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 16:58:47 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie()
{
}

// Constructor: initializes the zombie's name
Zombie::Zombie(std::string name) : name(name)
{
}

// Copy constructor
Zombie::Zombie(const Zombie& other) : name(other.name)
{
}

// Assignment operator
Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return *this;
}

// Destructor: displays a message when destroyed
Zombie::~Zombie()
{
	std::cout << name << " has been destroyed !!!" << std::endl;
}

// Announce method: Zombies announce themselves
void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Setter : sets the zombie's name
void Zombie::setName(std::string name)
{
	this->name = name;
}