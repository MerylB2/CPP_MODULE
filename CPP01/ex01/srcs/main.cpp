/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:52:53 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 17:32:17 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int main(int ac, char* argv[])
{
	if (ac != 1 && ac != 3)
	{
		std::cout << "Usage: " << argv[0] << " [zombieName hordeSize]" << std::endl;
		return 1;
	}

	// Set default values
	std::string zombieName = "Foo";
	int hordeSize = 5;

	// Parse arg if provided
	if (ac == 3)
	{
		zombieName = argv[1];
		hordeSize = std::atoi(argv[2]);
	}

	std::cout << "Creating a horde of " << hordeSize << " zombies named '" << zombieName << "'" << std::endl;

	// Create zombie horde
	Zombie* horde = zombieHorde(hordeSize, zombieName);

	if (!horde)
	{
		std::cout << "Failed to create zombie horde!" << std::endl;
		return 1;
	}
	
	// Make each zombie announce itself
	std::cout << "\033[1;37;42m" << "\n--- Zombie Horde is coming - RUN!!! ---" << "\033[0m" << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();
	}
	
	// Clean up memory - IMPORTANT: use delete[] for arrays!
	std::cout << "\033[1;37;44m" << "\n--- Destroying Zombie Horde ---" << "\033[0m" << std::endl;
	delete[] horde;
    
    return 0;
}