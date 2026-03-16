/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 11:31:14 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

// CLASSE ABSTRAITE - Animal ne peut plus etre instancie :
// makeSound() = 0 rend Animal ABSTRAITE
//
// Difference ex01 vs ex02 :
// ex01 : virtual void makeSound() const;      -> Animal instanciable
// ex02 : virtual void makeSound() const = 0;  -> Animal NON instanciable
//
// POURQUOI rendre Animal abstraite ?
// - Un "Animal" generique n'a pas de sens (quel son fait un "Animal" ?)
// - Seules les classes concretes (Dog, Cat) ont un comportement defini
// - Force les classes derivees a implementer makeSound()
//
// CE QUI CHANGE :
// Animal a;              // ERREUR : classe abstraite
// Animal* a = new Animal();  // ERREUR : classe abstraite
// Animal* a = new Dog();     // OK : Dog est concrete
//
// Animal reste utilisable comme TYPE (pointeur/reference) pour le polymorphisme

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& newAnimal);
		Animal& operator=(const Animal& other_Animal);
		virtual ~Animal();

		virtual void makeSound() const = 0;  // = 0 : PURE VIRTUAL -> classe abstraite
		std::string getType() const;
};
