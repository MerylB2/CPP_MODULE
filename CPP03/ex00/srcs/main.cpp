/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 01:05:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 02:16:28 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "\033[1;95m" << "===== Some Tests ====="   << "\033[0m" << std::endl;
    ClapTrap a;                     // Default constructor
    ClapTrap b("Enemy");            // constructor with parameter
    ClapTrap c(b);                  // Copy of constructor
    ClapTrap d;
    d = b;                          // Assignement operator
    
    std::cout << "\033[1;36m" << "\n===== Attack Test ====="   << "\033[0m" << std::endl;
    b.attack("Robot");
    
    std::cout << "\033[1;98m" << "\n===== Take Damage Test ====="   << "\033[0m" << std::endl;
    b.takeDamage(5);
    //b.takeDamage(10);                        // should be destroy
    
    std::cout << "\033[1;92m" << "\n===== Be Repaired Test ====="   << "\033[0m" << std::endl;
    a.beRepaired(3);                          // un pt d'energie depensé
    b.beRepaired(3);                          // un pt d'energie depensé


    std::cout << "\033[1;37m" << "\n===== Energie Epuisée Test ====="  << "\033[0m" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cout << "Attack " << i << ": ";
        a.attack("Target");                 // apres 9 attaques, plus d'énergie
    }
    
    
    std::cout << "\033[1;93m" << "\n===== Destructeurs ====="   << "\033[0m" << std::endl;
    return 0;
}