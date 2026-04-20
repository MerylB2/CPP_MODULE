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

// CLASSE CONCRETE derivee de Animal (abstraite) :
// Dog DOIT implementer makeSound() car c'est une methode pure virtuelle dans Animal
//
// Dog est instanciable car elle implemente TOUTES les methodes pures virtuelles
// Animal* ptr = new Dog();  // OK
// ptr->makeSound();         // Appelle Dog::makeSound()
//
// Combine ex01 (deep copy Brain) + ex02 (classe abstraite)

class Dog : public Animal
{
	private:
		Brain* brain;

	public:
		Dog();
		Dog(const Dog& newDog);
		Dog& operator=(const Dog& other_Dog);
		~Dog();

		void makeSound() const;  // OBLIGATOIRE : implemente la methode pure virtuelle
		Brain* getBrain() const;
};
