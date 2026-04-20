/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:51:27 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include " Brain.hpp"

// DOG avec BRAIN - Deep copy obligatoire :
//
// ALLOCATION DYNAMIQUE :
// - Constructeur : brain = new Brain();
// - Destructeur  : delete brain;
//
// DEEP COPY dans constructeur de copie :
// Dog(const Dog& src) {
//     this->brain = new Brain(*src.brain);  // Nouveau Brain, copie des idees
// }
//
// DEEP COPY dans operator= :
// Dog& operator=(const Dog& src) {
//     if (this != &src) {
//         delete this->brain;               // Libere l'ancien
//         this->brain = new Brain(*src.brain); // Nouveau avec copie
//     }
//     return *this;
// }

class Dog : public Animal
{
	private:
		Brain* brain;  // Pointeur -> DEEP COPY obligatoire

	public:
		Dog();
		Dog(const Dog& newDog);              // Deep copy du Brain
		Dog& operator=(const Dog& other_Dog); // Deep copy du Brain
		~Dog();                               // delete brain

		void makeSound() const;
		Brain* getBrain() const;
};
