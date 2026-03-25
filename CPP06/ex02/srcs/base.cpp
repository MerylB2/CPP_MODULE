/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:09:03 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/25 17:15:59 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include "colors.hpp"

Base::~Base()
{
    
}

Base* generate()
{
    switch (rand() % 3)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        std::cout << REDD << "Error : something went wrong ! " << RST << std::endl;
        return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << MAGN << "  type (ptr) : " << LIME << "A" << RST << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << MAGN << "  type (ptr) : " << LIME << "B" << RST << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << MAGN << "  type (ptr) : " << LIME << "C" << RST << std::endl;
    else
        std::cout << MAGN << "  type (ptr) : " << REDD << "unknown" << RST << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << MAGN << "  type (ref) : " << LIME << "A" << RST << std::endl;
        return;
    }
    catch(const std::exception&) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << MAGN << "  type (ref) : " << LIME << "B" << RST << std::endl;
        return;
    }
    catch(const std::exception&) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << MAGN << "  type (ref) : " << LIME << "C" << RST << std::endl;
        return;
    }
    catch(const std::exception&) {}

    std::cout << MAGN << "  type (ref) : " << REDD << "unknown" << RST << std::endl;
}