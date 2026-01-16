/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:49:21 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// Appelle d'abord Animal() puis initialise type
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& newCat) : Animal(newCat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = newCat;
}

Cat& Cat::operator=(const Cat& other_Cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other_Cat)
		this->type = other_Cat.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

// Polymorphisme : cette version est appelee quand l'objet est un Cat
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
