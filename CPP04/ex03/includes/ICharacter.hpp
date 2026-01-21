/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:17:09 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:14:16 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria; // Declaration anticipée pour eviter les dependances circulaires

class ICharacter
{
    public:
        virtual ~ICharacter() {} // Destructeur virtuel

        virtual std::string const &getName() const = 0; // Methode virtuelle pure

        virtual void equip(AMateria* materia) = 0;    // Equipe une Materia
        virtual void unequip(int idx) = 0;      // Desequipe une Materia
        virtual void use(int idx, ICharacter& target) = 0; // Utilise la Materia a l'index idx sur target
        virtual AMateria* getMateria(int idx) const = 0; // Methode pour obtenir une Materia a l'index idx
        
};
