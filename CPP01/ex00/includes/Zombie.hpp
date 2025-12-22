/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:52:45 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 16:03:05 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
	
public:
	Zombie(std::string name);	// Constructor with name
	~Zombie();					// Destructor with destruction message
	
	void announce(void);		// Makes zombie announce itself
};

// Allocates a zombie on the heap and returns its pointer
Zombie* newZombie(std::string name);

// Creates a temporary zombie on the stack that announces itself then destructs
void randomChump(std::string name);

#endif