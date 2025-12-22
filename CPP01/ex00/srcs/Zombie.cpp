/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:53:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 16:15:01 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor: initializes the zombie's name
Zombie::Zombie(std::string name) : name(name)
{
}

// Destructor: displays a message when destroyed
Zombie::~Zombie()
{
	std::cout << name << " has been destroyed !!!" << std::endl << std::endl;
}

// Announce method: Zombies announce themselves
void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
