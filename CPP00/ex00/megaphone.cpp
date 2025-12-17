/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:20:10 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/10/17 17:51:33 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
        return 0;
    }

    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
            std::cout << (char)std::toupper(av[i][j]);
        if (av[i] != NULL)
            std::cout << " ";
    }
    std:: cout << std::endl;
    return 0;
}
