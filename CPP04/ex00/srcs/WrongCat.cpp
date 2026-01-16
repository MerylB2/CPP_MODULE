/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:55:28 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrong_Cat) : WrongAnimal(wrong_Cat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrong_Cat;
}

WrongCat& WrongCat::operator=(const WrongCat& wrong_Cat)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &wrong_Cat)
		this->type = wrong_Cat.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// Cette methode ne sera JAMAIS appelee via un pointeur WrongAnimal*
// car WrongAnimal::makeSound() n'est pas virtual
void WrongCat::makeSound() const
{
	std::cout << "Meow! Meow! (WrongCat)" << std::endl;
}
