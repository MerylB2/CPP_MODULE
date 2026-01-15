/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 01:05:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 14:19:00 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
    std::cout << "\033[1;95m\033[4m" << "\n*************************** CLAPTRAP TESTS ***************************" << "\033[0m" << std::endl << std::endl;
    ClapTrap a;                     // Default constructor
    ClapTrap b("Enemy");            // constructor with parameter
    ClapTrap c(b);                  // Copy of constructor
    ClapTrap d;
    d = b;                          // Assignement operator

    std::cout << "\033[1;36m" << "\n===== ClapTrap Attack Test ====="   << "\033[0m" << std::endl;
    b.attack("Robot");

    std::cout << "\033[1;91m" << "\n===== ClapTrap Take Damage Test ====="   << "\033[0m" << std::endl;
    d.takeDamage(5);
    b.takeDamage(10);                       

    std::cout << "\033[1;92m" << "\n===== ClapTrap Be Repaired Test ====="   << "\033[0m" << std::endl;
    a.beRepaired(3);
    b.beRepaired(3);

    std::cout << "\033[1;37m" << "\n===== ClapTrap No more energy Test ====="  << "\033[0m" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cout << "Attack " << i << ": ";
        a.attack("Target");
    }

    std::cout << "\033[1;94m\033[4m" << "\n*************************** SCAVTRAP TESTS ***************************" << "\033[0m" << std::endl <<std::endl;
    ScavTrap s1;
    ScavTrap s2("Scavvy");

    std::cout << "\033[1;96m" << "\n===== ScavTrap Attack Test ====="   << "\033[0m" << std::endl;
    s2.attack("Enemy");

    std::cout << "\033[1;91m" << "\n===== ScavTrap TakeDamage Test ====="   << "\033[0m" << std::endl;
    s2.takeDamage(30);

    std::cout << "\033[1;92m" << "\n===== ScavTrap BeRepaired Test ====="   << "\033[0m" << std::endl;
    s2.beRepaired(20);

    std::cout << "\033[1;34m" << "\n===== ScavTrap GuardGate Test ====="   << "\033[0m" << std::endl;
    s2.guardGate();

    std::cout << "\033[1;32m\033[4m" << "\n*************************** FRAGTRAP TESTS ***************************" << "\033[0m" << std::endl << std::endl;
    FragTrap f1;
    FragTrap f2("Fraggy");

    std::cout << "\033[1;96m" << "\n===== FragTrap Attack Test ====="   << "\033[0m" << std::endl;
    f2.attack("Enemy");

    std::cout << "\033[1;91m" << "\n===== FragTrap TakeDamage Test ====="   << "\033[0m" << std::endl;
    f2.takeDamage(50);

    std::cout << "\033[1;92m" << "\n===== FragTrap BeRepaired Test ====="   << "\033[0m" << std::endl;
    f2.beRepaired(30);

    std::cout << "\033[1;38m" << "\n===== FragTrap HighFivesGuys Test ====="   << "\033[0m" << std::endl;
    f2.highFivesGuys();

    std::cout << "\033[1;93m\033[4m" << "\n*************************** Destructors ****************************"   << "\033[0m" << std::endl;
    return 0;
}