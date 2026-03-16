/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMatreria.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:54:58 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:10:42 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "colors.hpp"

class ICharacter; // Declaration anticipee pour eviter les dependances circulaires

// CLASSE ABSTRAITE (Abstract Class) :
// - Contient au moins une methode virtuelle pure (= 0)
// - Ne peut PAS etre instanciee directement (new AMateria() interdit)
// - Fournit une base commune avec attributs (type) et methodes implementees (getType, use)
// - Les classes derivees (Ice, Cure) DOIVENT implementer clone()
//
// Difference avec Interface :
// - Interface = que des methodes virtuelles pures, pas d'attributs
// - Classe abstraite = peut avoir attributs + methodes implementees
//
// Convention de nommage : prefixe "A" pour Abstract (AMateria, AAnimal...)

class AMateria
{
    protected:
        std::string type; // Attribut protege : accessible par les classes derivees

    public:
        AMateria();
        AMateria(const std::string& type);
        AMateria(const AMateria& newMateria);
        AMateria& operator=(const AMateria& other_Materia);
        virtual ~AMateria(); // Destructeur VIRTUEL obligatoire pour polymorphisme

        std::string const& getType() const; // Getter - methode concrete (implementee)

        virtual AMateria* clone() const = 0; // PURE VIRTUAL : Prototype pattern - chaque derivee retourne son propre clone
        virtual void use(ICharacter& target); // VIRTUAL : comportement par defaut, redefinissable
};
