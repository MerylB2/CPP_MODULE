/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/24 15:59:04 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include " Brain.hpp"

// CAT avec BRAIN - Deep copy obligatoire :
// Meme logique que Dog - chaque Cat a son propre Brain
//
// TEST de la deep copy :
// Cat c1; c1.getBrain()->setIdea(0, "fish");
// Cat c2 = c1;                              // Deep copy
// c2.getBrain()->setIdea(0, "sleep");
// c1.getBrain()->getIdea(0); // -> "fish" (pas modifie)
// c2.getBrain()->getIdea(0); // -> "sleep"
// Si shallow copy : les deux auraient "sleep" -> ERREUR

class Cat : public Animal
{
	private:
		Brain* brain;  // Pointeur -> DEEP COPY obligatoire

	public:
		Cat();
		Cat(const Cat& newCat);              // Deep copy du Brain
		Cat& operator=(const Cat& other_Cat); // Deep copy du Brain
		~Cat();                               // delete brain

		void makeSound() const;
		Brain* getBrain() const;
};
