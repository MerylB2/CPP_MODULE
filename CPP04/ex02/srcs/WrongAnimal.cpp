/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:53:48 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << "WrongAnimal parameterized constructor called for " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrong)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrong;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrong)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &wrong)
		this->type = wrong.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Sans virtual, cette version sera TOUJOURS appelee via un pointeur WrongAnimal*
void WrongAnimal::makeSound() const
{
	std::cout << "* Wrong animal sound *" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
