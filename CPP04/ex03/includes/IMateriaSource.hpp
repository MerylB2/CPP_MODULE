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

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {} // Destructeur virtuel
        virtual void learnMateria(AMateria* materia) = 0; // Methode virtuelle pure
        virtual AMateria* createMateria(std::string const & materia_type) = 0; // Methode virtuelle pure
};