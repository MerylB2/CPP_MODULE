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

class AMateria; // Declaration anticipee pour eviter les dependances circulaires

// INTERFACE (Pure Abstract Class) :
// En C++98, pas de mot-cle "interface" -> on utilise une classe purement abstraite
//
// Caracteristiques d'une Interface :
// - TOUTES les methodes sont virtuelles pures (= 0)
// - AUCUN attribut (pas de donnees membres)
// - Destructeur virtuel avec corps vide {} (pas = 0, sinon pas de destruction polymorphe)
// - Ne peut PAS etre instanciee (new ICharacter() interdit)
//
// Avantage : definit un CONTRAT que toutes les classes derivees doivent respecter
// Le code client utilise ICharacter* au lieu de Character* -> polymorphisme et decouplage
//
// Convention de nommage : prefixe "I" pour Interface (ICharacter, IMateriaSource...)

class ICharacter
{
    public:
        virtual ~ICharacter() {} // Destructeur virtuel avec corps vide (PAS = 0)

        virtual std::string const& getName() const = 0;          // Pure virtual : retourne le nom
        virtual void equip(AMateria* materia) = 0;               // Pure virtual : equipe une Materia
        virtual void unequip(int idx) = 0;                       // Pure virtual : retire une Materia (sans delete!)
        virtual void use(int idx, ICharacter& target) = 0;       // Pure virtual : utilise la Materia sur target
        virtual AMateria* getMateria(int idx) const = 0;         // Pure virtual : getter pour acces externe
};
