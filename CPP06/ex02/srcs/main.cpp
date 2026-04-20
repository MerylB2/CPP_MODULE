/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:09:03 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/25 17:10:57 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include "colors.hpp"

int main()
{
    srand(time(NULL));
    Base* type = generate();

    std::cout << BOLD << GOLD << SOUL
        << "\n****** Base Tests (ex02) ******"
        << RST << std::endl << std::endl;

    std::cout << CYAN << "===== With Pointer =====" << RST << std::endl;
    identify(type);
    
    std::cout << CYAN << "===== With Reference =====" << RST << std::endl;
    identify(*type);

    delete type;
    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}