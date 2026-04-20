/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:09:03 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/25 16:17:34 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"
#include "colors.hpp"

int main()
{
    std::cout << BOLD << RUBY << SOUL
        << "\n****** Serializer Tests (ex01) ******"
        << RST << std::endl << std::endl;

    Data data;

    std::cout << CYAN << "===== Fill Data =====" << RST << std::endl;
    std::cout << GOLD << "  value (int)    : " << RST;
    std::cin >> data.value;
	std::cout << GRY2 << BLKF << "  value : \"" << data.value << "\"" << RST
        << std::endl;
    std::cout << GOLD << "  ratio (double) : " << RST;
    std::cin >> data.ratio;
	std::cout << GRY2 << BLKF << "  value : \"" << data.ratio << "\"" << RST
        << std::endl;
    std::cin.ignore();
    std::cout << GOLD << "  label (string) : " << RST;
    std::getline(std::cin, data.label);
	std::cout << GRY2 << BLKF << "  value : \"" << data.label<< "\"" << RST
        << std::endl;
    std::cout << std::endl;

    std::cout << CYAN << "===== Original Data =====" << RST << std::endl;
    std::cout << GOLD << "  address : " << LIME << &data        << RST << std::endl;
    std::cout << GOLD << "  value   : " << LIME << data.value   << RST << std::endl;
    std::cout << GOLD << "  ratio   : " << LIME << data.ratio   << RST << std::endl;
    std::cout << GOLD << "  label   : " << LIME << data.label   << RST << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << CYAN << "\n===== Serialized =====" << RST << std::endl;
    std::cout << GOLD << "  raw (uintptr_t) : " << LIME << raw  << RST << std::endl;

    Data* result = Serializer::deserialize(raw);
    std::cout << CYAN << "\n===== Deserialized =====" << RST << std::endl;
    std::cout << GOLD << "  address : " << LIME << result        << RST << std::endl;
    std::cout << GOLD << "  value   : " << LIME << result->value << RST << std::endl;
    std::cout << GOLD << "  ratio   : " << LIME << result->ratio << RST << std::endl;
    std::cout << GOLD << "  label   : " << LIME << result->label << RST << std::endl;

    std::cout << CYAN << "\n===== Comparison =====" << RST << std::endl;
    if (&data == result)
        std::cout << GOLD << "  Pointers identical : " << LIME << "yes" << RST << std::endl;
    else
        std::cout << GOLD << "  Pointers identical : " << REDD << "no"  << RST << std::endl;

    std::cout << RUBY << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
