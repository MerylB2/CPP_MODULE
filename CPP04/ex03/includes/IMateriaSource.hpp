/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:56:10 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 14:00:05 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AMateria.hpp"

// INTERFACE pour le FACTORY PATTERN :
// IMateriaSource definit le contrat d'une "fabrique" de Materias
//
// Factory Pattern :
// - Permet de creer des objets sans connaitre leur type concret
// - Le code client utilise createMateria("ice") au lieu de new Ice()
// - Avantage : decouplage, flexibilite, ajout facile de nouveaux types
//
// Combine avec Prototype Pattern :
// - learnMateria() stocke des "prototypes" (modeles)
// - createMateria() clone le prototype correspondant au type demande

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}                                          // Destructeur virtuel
        virtual void learnMateria(AMateria* materia) = 0;                     // Stocke un prototype de Materia
        virtual AMateria* createMateria(std::string const& materia_type) = 0; // Cree un clone du prototype
};