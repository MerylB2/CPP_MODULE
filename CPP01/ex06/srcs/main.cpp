/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:39:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 12:21:45 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " <level>" << std::endl;
		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	
	Harl harl;
	std::string level;
	
	level = av[1];
	harl.complain(level);
	
	return 0;
}








/* first way */
// int main(int ac, char* av[])
// {
// 	if (ac != 2)
// 	{
// 		std::cout << "Usage: " << av[0] << " <level>" << std::endl;
// 		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
// 		return 1;
// 	}
	
// 	Harl harl;
// 	int level = harl.getLevel(av[1]);
	
// 	switch (level)
// 	{
// 		case 0:
// 			harl.complain("DEBUG");
// 		case 1:
// 			harl.complain("INFO");
// 		case 2:
// 			harl.complain("WARNING");
// 		case 3:
// 			harl.complain("ERROR");
// 			break;
// 		default:
// 			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// 			break;
// 	}
	
// 	return 0;
// }