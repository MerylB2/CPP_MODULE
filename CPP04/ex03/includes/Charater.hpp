/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Charater.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:55:45 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:11:51 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMatreria.hpp"

#define MAX_INVENTORY 4

class Character: virtual public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[MAX_INVENTORY]; // Inventaire de Materia (taille fixe de 4)
        
    public:
        Character();
        Character (const std::string Character);
        Character (const Character& newCharacter);
        Character& operator=(const Character& other_Character);
        ~Character();

        const std::string &getName() const; // Implemente la methode pure virtuelle de ICharacter
        AMateria* getMateria(int idx) const; // Methode pour obtenir une Materia a l'index idx
        
        void equip(AMateria* materia);            // Implemente la methode pure virtuelle de
        void unequip(int idx) = 0;
        void use(int idx, ICharacter& target) = 0;
};