/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 01:05:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 15:49:00 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main()
{
    std::cout << "\033[1;93m\033[4m" << "\n*************************** DIAMONDTRAP TESTS ***************************" << "\033[0m" << std::endl << std::endl;
    DiamondTrap d1;
    DiamondTrap d2("Diamyy");

    std::cout << "\033[1;96m" << "\n===== DiamondTrap Attack Test (uses ScavTrap::attack) ====="   << "\033[0m" << std::endl;
    d2.attack("Enemy");

    std::cout << "\033[1;91m" << "\n===== DiamondTrap TakeDamage Test ====="   << "\033[0m" << std::endl;
    d2.takeDamage(40);

    std::cout << "\033[1;92m" << "\n===== DiamondTrap BeRepaired Test ====="   << "\033[0m" << std::endl;
    d2.beRepaired(25);

    std::cout << "\033[1;34m" << "\n===== DiamondTrap GuardGate Test (from ScavTrap) ====="   << "\033[0m" << std::endl;
    d2.guardGate();

    std::cout << "\033[1;33m" << "\n===== DiamondTrap HighFivesGuys Test (from FragTrap) ====="   << "\033[0m" << std::endl;
    d2.highFivesGuys();

    std::cout << "\033[1;35m" << "\n===== DiamondTrap WhoAmI Test ====="   << "\033[0m" << std::endl;
    d2.whoAmI();

    std::cout << "\033[1;93m\033[4m" << "\n*************************** Destructors ****************************"   << "\033[0m" << std::endl;
    return 0;
}
