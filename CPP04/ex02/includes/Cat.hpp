/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/24 15:59:23 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include " Brain.hpp"

// CLASSE CONCRETE derivee de Animal (abstraite) :
// Cat DOIT implementer makeSound() car c'est une methode pure virtuelle dans Animal
//
// Cat est instanciable car elle implemente TOUTES les methodes pures virtuelles
// Animal* ptr = new Cat();  // OK
// ptr->makeSound();         // Appelle Cat::makeSound()

class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat& newCat);
		Cat& operator=(const Cat& other_Cat);
		~Cat();

		void makeSound() const;  // OBLIGATOIRE : implemente la methode pure virtuelle
		Brain* getBrain() const;
};
