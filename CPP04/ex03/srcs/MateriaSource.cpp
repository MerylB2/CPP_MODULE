/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:30:29 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/21 13:00:00 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->materia_slots[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& newMateriaSource)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (newMateriaSource.materia_slots[i] != NULL)
			this->materia_slots[i] = newMateriaSource.materia_slots[i]->clone();
		else
			this->materia_slots[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other_MateriaSource)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other_MateriaSource)
	{
		for (int i = 0; i < MAX_INVENTORY; i++)
		{
			if (this->materia_slots[i] != NULL)
			{
				delete this->materia_slots[i];
				this->materia_slots[i] = NULL;
			}
			if (other_MateriaSource.materia_slots[i] != NULL)
				this->materia_slots[i] = other_MateriaSource.materia_slots[i]->clone();
			else
				this->materia_slots[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->materia_slots[i] != NULL)
		{
			delete this->materia_slots[i];
			this->materia_slots[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cout << "Cannot learn NULL materia." << std::endl;
		return;
	}
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->materia_slots[i] == NULL)
		{
			this->materia_slots[i] = materia;
			std::cout << "Learned " << materia->getType() << " materia in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full. Cannot learn more materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & materia_type)
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->materia_slots[i] != NULL && this->materia_slots[i]->getType() == materia_type)
			return this->materia_slots[i]->clone();
	}
	std::cout << "Materia type \"" << materia_type << "\" not found." << std::endl;
	return NULL;
}
