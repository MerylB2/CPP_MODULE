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

class Cure: virtual public AMateria
{
    public:
        Cure();
        Cure (const Cure& newCure);
        Cure (const std::string &cure);
        Cure &operator=(const Cure& other_Cure);
        ~Cure();
        
        AMateria* clone() const;
        void use(class ICharacter& target); // Redefinit la methode virtuelle de AMateria      
};