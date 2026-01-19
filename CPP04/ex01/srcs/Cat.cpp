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

// Alloue un nouveau Brain sur le heap
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

// Deep copy : cree un NOUVEAU Brain (pas copie du pointeur)
Cat::Cat(const Cat& newCat) : Animal(newCat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*newCat.brain);  // Deep copy du Brain
}

// Deep copy : copie le contenu du Brain, pas le pointeur
Cat& Cat::operator=(const Cat& other_Cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other_Cat)
	{
		this->type = other_Cat.type;
		*this->brain = *other_Cat.brain;  // Deep copy du contenu
	}
	return *this;
}

// Libere le Brain avant destruction
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->brain;
}
