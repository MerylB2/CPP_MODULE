/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:39:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 10:55:18 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	
	std::cout << "=== HARL COMPLAINT TEST ===" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "Testing INFO level:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "Testing WARNING level:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "Testing ERROR level:" << std::endl;
	harl.complain("ERROR");
	
	std::cout << "Testing invalid level:" << std::endl;
	harl.complain("INVALID");

	std::cout << std::endl;
	
	std::cout << "Testing empty level:" << std::endl;
	harl.complain("");
	
	std::cout << std::endl;
	
	std::cout << "Testing lowercase level:" << std::endl;
	harl.complain("debug");

	std::cout << std::endl;
	
	std::cout << "=== END OF TESTS ===" << std::endl;
	
	return 0;
}

// int main(int ac, char** av)
// {
// 	if (ac != 2)
// 	{
// 		std::cout << "Usage: " << av[0] << " <level>" << std::endl;
// 		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
// 		return 1;
// 	}
	
// 	Harl harl;
// 	harl.complain(av[1]);
	
// 	return 0;
// }
