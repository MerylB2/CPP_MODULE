/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:19:16 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 18:47:20 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    //Create a string variable
    std::string str = "HI THIS IS BRAIN";
    
    //Create a pointer to the string
    std::string* stringPTR = &str;

    //Create a reference to the string
    std::string& stringREF = str;

    /* Print memories address */
    std::cout << "Memory address of the string var: " << &str << std::endl;

    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

    /* Print Values */
    std::cout << "Value of the string variable: " << str << std::endl;

    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}