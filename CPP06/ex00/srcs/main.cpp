/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:36:40 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/25 15:39:23 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << REDD << "Usage: " << av[0] << " <literal>" << RST << std::endl;
        return 1;
    }
    std::cout << BOLD << TURQ << SOUL
        << "\n****** ScalarConverter Tests (ex00) ******"
        << RST << std::endl;
    std::cout << GRY2 << BLKF << "  input : \"" << av[1] << "\"" << RST
        << std::endl << std::endl;
    ScalarConverter::convert(av[1]);
    std::cout << TURQ << "\n===== End of conversion =====" << RST << std::endl;
    return 0;
}
