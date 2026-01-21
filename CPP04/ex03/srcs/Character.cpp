/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:14:24 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:26:49 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character() : name("Default_Character")
{
    for (int i = 0; i < MAX_INVENTORY; i++)
        this->materia_slots[i] = NULL;
    std::cout << "Character default constructor called for " << this->name << std::endl;
}

Character::Character (const std::string& name) : name(name)
{
    for (int i = 0; i < MAX_INVENTORY; i++)
        this->materia_slots[i] = NULL;
    std::cout << "Character parameterized constructor called for " << this->name << std::endl;
}
Character::Character (const Character& newCharacter)
{
    std::cout << "Character copy constructor called for " << newCharacter.name << std::endl;

    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (newCharacter.materia_slots[i] != NULL)
            this->materia_slots[i] = newCharacter.materia_slots[i]->clone();
        else
            this->materia_slots[i] = NULL;
    }
}

Character& Character::operator=(const Character& other_Character)
{
    std::cout << "Character copy assignment operator called for " << other_Character.name << std::endl;
    if (this != &other_Character)
    {
        this->name = other_Character.name;
        for (int i = 0; i < MAX_INVENTORY; i++)
        {
            if (this->materia_slots[i] != NULL)
            {
                delete this->materia_slots[i];
                this->materia_slots[i] = NULL;
            }
            if (other_Character.materia_slots[i] != NULL)
                this->materia_slots[i] = other_Character.materia_slots[i]->clone();
            else
                this->materia_slots[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called for " << this->name << std::endl;
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (this->materia_slots[i] != NULL)
        {
            delete this->materia_slots[i];
            this->materia_slots[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return this->name;
}


AMateria* Character::getMateria(int idx) const
{
    if (idx < 0 || idx >= MAX_INVENTORY)
    {
        std::cout << "Invalid index: " << idx << ". Valid range is 0 to " << MAX_INVENTORY - 1 << "." << std::endl;
        return NULL;
    }
    return this->materia_slots[idx];
}

void Character::equip(AMateria* materia)
{
    if (materia == NULL)
    {
        std::cout << "Cannot equip NULL materia." << std::endl;
        return;
    }
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (this->materia_slots[i] == NULL)
        {
            this->materia_slots[i] = materia;
            std::cout << "Equipped " << materia->getType() << " materia in slot " << i << " for " << this->name << "." << std::endl;
            return;
        }
    }
    std::cout << this->name << "'s inventory is full. Cannot equip more materia." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_INVENTORY)
    {
        std::cout << "Invalid index: " << idx << ". Valid range is 0 to " << MAX_INVENTORY - 1 << "." << std::endl;
        return;
    }
    if (this->materia_slots[idx] != NULL)
    {
        std::cout << "Unequipped " << this->materia_slots[idx]->getType() << " materia from slot " << idx << " for " << this->name << "." << std::endl;
        this->materia_slots[idx] = NULL;
    }
    else
    {
        std::cout << "No materia to unequip in slot " << idx << " for " << this->name << "." << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= MAX_INVENTORY)
    {
        std::cout << "Invalid index: " << idx << ". Valid range is 0 to " << MAX_INVENTORY - 1 << "." << std::endl;
        return;
    }
    if (this->materia_slots[idx] != NULL)
    {
        this->materia_slots[idx]->use(target);
    }
    else
    {
        std::cout << "No materia in slot " << idx << " to use for " << this->name << "." << std::endl;
    }
}

