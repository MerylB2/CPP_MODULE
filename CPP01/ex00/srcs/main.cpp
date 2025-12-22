/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:52:53 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 16:15:13 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char* argv[])
{
	std::string zombieName;
	
	if (argc > 2)
	{
		std::cout << "Usage: " << argv[0] << " [zombie_name]" << std::endl;
		return 1;
	}
	else if (argc == 2)
		zombieName = argv[1];
	else
		zombieName = "Foo";
	
	// Heap allocation: zombie persists until manually deleted
	Zombie* heapZombie = newZombie(zombieName + "_Heap");
	heapZombie->announce();
	delete heapZombie;
	
	//std::cout << std::endl;
	
	// Stack allocation: zombie automatically destroyed at end of scope
	randomChump(zombieName + "_Stack");
	
	return 0;
}
