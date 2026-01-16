/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:51:51 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// Appelle d'abord Animal() puis initialise type
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& newDog) : Animal(newDog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = newDog;
}

Dog& Dog::operator=(const Dog& other_Dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other_Dog)
		this->type = other_Dog.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// Polymorphisme : cette version est appelee quand l'objet est un Dog
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
