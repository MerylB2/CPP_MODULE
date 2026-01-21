/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Charater.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:55:45 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/21 12:54:31 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_INVENTORY 4

class Character: virtual public ICharacter
{
    private:
        std::string name;
        AMateria* materia_slots[MAX_INVENTORY]; // Inventaire de Materia (taille fixe de 4)
        
    public:
        Character();
        Character (const std::string& name);
        Character (const Character& newCharacter);
        Character& operator=(const Character& other_Character);
        ~Character();

        const std::string &getName() const; 
        AMateria* getMateria(int idx) const; 
        
        void equip(AMateria* materia);          
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};