/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 02:03:46 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

// CLASSE DE BASE pour le POLYMORPHISME :
// Animal est la classe parent de Dog et Cat
//
// VIRTUAL - Le mot-cle qui change tout :
// - makeSound() est VIRTUAL -> appelle la methode de la classe REELLE
//   Animal* a = new Dog(); a->makeSound(); -> "Woof!" (Dog::makeSound)
// - ~Animal() est VIRTUAL -> delete appelle le bon destructeur
//   Sans virtual : delete Dog via Animal* ne detruit que la partie Animal!
//
// PROTECTED vs PRIVATE :
// - protected : accessible par Animal ET ses classes derivees (Dog, Cat)
// - private : accessible UNIQUEMENT par Animal
// Ici "type" est protected car Dog/Cat doivent pouvoir le modifier

class Animal
{
	protected:
		std::string type;  // Protected : Dog/Cat peuvent acceder a type

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& newAnimal);
		Animal& operator=(const Animal& other_Animal);
		virtual ~Animal();               // VIRTUAL : destruction polymorphe

		virtual void makeSound() const;  // VIRTUAL : comportement polymorphe
		std::string getType() const;
};
