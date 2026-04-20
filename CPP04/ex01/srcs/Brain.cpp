/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/24 15:18:43 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

// Deep copy : copie toutes les 100 idees
Brain::Brain(const Brain& newBrain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = newBrain;
}

// Deep copy : copie toutes les 100 idees
Brain& Brain::operator=(const Brain& other_Brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other_Brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other_Brain.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;  // Assigne l'idée à l'index spécifié
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return ""; // Retourne une chaîne vide si l'index est invalide
}
