/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:19:13 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 18:15:05 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

// Allocates N zombies in a single allocation and initializes them
Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	// Allocation of array for N zombies with "new[]"
	Zombie* horde = new Zombie[N];
	
	//Initialization of each zombie with the given name and index
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << name << "_" << i;
		horde[i].setName(ss.str());
	}
	
	return horde;
}
