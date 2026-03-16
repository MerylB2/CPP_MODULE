/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:12:44 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:03:20 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

// CLASSE CONCRETE derivee de AMateria :
// Ice implemente les methodes virtuelles pures de AMateria
//
// Prototype Pattern (clone) :
// - clone() retourne new Ice(*this) -> copie profonde de l'objet
// - Permet de copier sans connaitre le type concret (polymorphisme)
// - Utilise par MateriaSource::createMateria() pour creer des copies
//
// Polymorphisme (use) :
// - use() est virtual dans AMateria -> Ice::use() est appelee meme via AMateria*
// - Affiche "* shoots an ice bolt at <target> *"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& newIce);
        Ice(const std::string& ice);
        Ice& operator=(const Ice& other_Ice);
        ~Ice();

        AMateria* clone() const;             // Prototype pattern : retourne new Ice(*this)
        void use(ICharacter& target);        // Override : "* shoots an ice bolt at <target> *"
};