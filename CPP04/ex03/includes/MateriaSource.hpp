/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:06:24 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:07:43 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

// FACTORY PATTERN + PROTOTYPE PATTERN :
// MateriaSource est une "fabrique" qui cree des Materias a la demande
//
// Comment ca marche :
// 1. learnMateria(new Ice()) -> stocke Ice comme prototype dans un slot
// 2. createMateria("ice")    -> cherche le prototype "ice" et retourne un clone
//
// Avantages :
// - Le code client n'a pas besoin de connaitre Ice ou Cure
// - Il utilise juste createMateria("ice") -> decouplage
// - Ajouter un nouveau type = juste learnMateria(new NewType())
//
// DEEP COPY obligatoire :
// - materia_slots contient des pointeurs vers les prototypes
// - Constructeur de copie et operator= doivent cloner chaque prototype
// - Destructeur doit delete tous les prototypes

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia_slots[MAX_INVENTORY]; // Stocke les prototypes (4 max)

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& newMateriaSource);     // DEEP COPY des prototypes
        MateriaSource& operator=(const MateriaSource& other);     // DEEP COPY des prototypes
        ~MateriaSource();                                         // Delete tous les prototypes

        void learnMateria(AMateria* materia);                     // Stocke un prototype (prend ownership)
        AMateria* createMateria(std::string const& materia_type); // Retourne un CLONE du prototype
};