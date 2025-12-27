/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:52:53 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 08:39:06 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char* av[])
{
	std::string zombieName;
	
	if (ac > 2)
	{
		std::cout << "Usage: " << av[0] << " [zombie_name]" << std::endl;
		return 1;
	}
	else if (ac == 2)
		zombieName = av[1];
	else
		zombieName = "Foo";
	
	// Heap allocation: zombie persists until manually deleted
	Zombie* heapZombie = newZombie(zombieName + "_Heap");
	heapZombie->announce();
	delete heapZombie;
	
	// Stack allocation: zombie automatically destroyed at end of scope
	randomChump(zombieName + "_Stack");
	
	return 0;
}
