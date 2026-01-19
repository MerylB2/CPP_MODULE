/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:47:43 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal parameterized constructor called for " << this->type << std::endl;
}

Animal::Animal(const Animal& newAnimal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = newAnimal;
}

Animal& Animal::operator=(const Animal& other_Animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other_Animal)
		this->type = other_Animal.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "* Some generic animal sound *" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
