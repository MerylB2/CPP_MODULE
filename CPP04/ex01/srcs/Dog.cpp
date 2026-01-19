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

// Alloue un nouveau Brain sur le heap
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

// Deep copy : cree un NOUVEAU Brain (pas copie du pointeur)
Dog::Dog(const Dog& newDog) : Animal(newDog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*newDog.brain);  // Deep copy du Brain
}

// Deep copy : copie le contenu du Brain, pas le pointeur
Dog& Dog::operator=(const Dog& other_Dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other_Dog)
	{
		this->type = other_Dog.type;
		*this->brain = *other_Dog.brain;  // Deep copy du contenu
	}
	return *this;
}

// Libere le Brain avant destruction
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}
