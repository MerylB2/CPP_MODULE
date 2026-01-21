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

class IMateriaSource;

class MateriaSource: virtual public IMateriaSource
{
    private:
        AMateria* materia_slots[MAX_INVENTORY]; // Tableau de pointeurs vers AMateria (taille fixe de 4)
        
    public:
        MateriaSource();
        MateriaSource (const MateriaSource& newMateriaSource);
        MateriaSource& operator=(const MateriaSource& other_MateriaSource);
        ~MateriaSource();

        void learnMateria(AMateria* materia); // Implemente la methode pure virtuelle de IMateriaSource
        AMateria* createMateria(std::string const & materia_type); // Implemente la methode pure virtuelle de IMateriaSource
};