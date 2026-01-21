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

class ICharacter; // Declaration anticipée pour eviter les dependances circulaires

class AMateria
{
    protected:
        std::string type;
        
    public:
        AMateria();
        AMateria (const std::string& type);
        AMateria (const AMateria& newMateria);
        AMateria& operator=(const AMateria& other_Materia);
        virtual ~AMateria();

        std::string const &getType() const; // Returns the materia type
        
        virtual AMateria* clone() const = 0; // Pure virtual : doit etre implemente dans les classes derivees
        virtual void use(class ICharacter& target); // Virtual : peut etre redefinie dans les classes derivees
};
