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

// CLASSE CONCRETE implementant l'interface ICharacter :
// Character implemente TOUTES les methodes virtuelles pures de ICharacter
//
// DEEP COPY obligatoire :
// - materia_slots contient des pointeurs -> copie superficielle = danger
// - Constructeur de copie et operator= doivent cloner chaque Materia
// - Destructeur doit delete toutes les Materias
//
// GESTION MEMOIRE (ownership) :
// - equip() : Character prend possession de la Materia passee
// - unequip() : NE DELETE PAS la Materia (le sujet l'impose)
//   -> L'appelant doit sauvegarder le pointeur avant unequip pour eviter les fuites
// - Destructeur : delete toutes les Materias dans les slots
//
// Exemple de fuite memoire a eviter :
//   me->unequip(0);  // La Materia n'est plus referencee -> FUITE!
// Bonne pratique :
//   AMateria* tmp = me->getMateria(0);
//   me->unequip(0);
//   delete tmp;  // Pas de fuite

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* materia_slots[MAX_INVENTORY]; // Inventaire : 4 slots max

    public:
        Character();
        Character(const std::string& name);
        Character(const Character& newCharacter);        // DEEP COPY : clone les Materias
        Character& operator=(const Character& other);    // DEEP COPY : delete puis clone
        ~Character();                                    // Delete toutes les Materias

        const std::string& getName() const;
        AMateria* getMateria(int idx) const;             // Getter pour acces externe

        void equip(AMateria* materia);                   // Prend ownership de materia
        void unequip(int idx);                           // Retire SANS delete (attention fuites!)
        void use(int idx, ICharacter& target);           // Appelle materia->use(target)
};