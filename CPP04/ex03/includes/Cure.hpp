/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:06:15 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:13:14 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

// CLASSE CONCRETE derivee de AMateria :
// Cure implemente les methodes virtuelles pures de AMateria
//
// Prototype Pattern (clone) :
// - clone() retourne new Cure(*this) -> copie profonde de l'objet
// - Permet de copier sans connaitre le type concret (polymorphisme)
// - Utilise par MateriaSource::createMateria() pour creer des copies
//
// Polymorphisme (use) :
// - use() est virtual dans AMateria -> Cure::use() est appelee meme via AMateria*
// - Affiche "* heals <target>'s wounds *"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& newCure);
        Cure(const std::string& cure);
        Cure& operator=(const Cure& other_Cure);
        ~Cure();

        AMateria* clone() const;             // Prototype pattern : retourne new Cure(*this)
        void use(ICharacter& target);        // Override : "* heals <target>'s wounds *"
};