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

class Ice: virtual public AMateria
{
    public:
        Ice();
        Ice (const Ice& newIce);
        Ice (const std::string& ice);
        Ice &operator=(const Ice& other_Ice);
        ~Ice();

        AMateria* clone() const;
        void use(class ICharacter& target); // Redefinit la methode virtuelle de AMateria
};