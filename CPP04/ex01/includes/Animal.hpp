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

// CLASSE DE BASE pour le polymorphisme :
// Dans ex01, Dog et Cat ont maintenant un Brain* alloue dynamiquement
//
// DESTRUCTEUR VIRTUEL - Crucial avec allocation dynamique :
// Animal* a = new Dog();  // Dog alloue un Brain
// delete a;               // Sans virtual ~Animal : Brain jamais delete -> FUITE!
//                         // Avec virtual ~Animal : ~Dog() puis ~Animal() -> OK

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& newAnimal);
		Animal& operator=(const Animal& other_Animal);
		virtual ~Animal();               // VIRTUAL : destruction polymorphe (appelle ~Dog/~Cat)

		virtual void makeSound() const;  // VIRTUAL : polymorphisme
		std::string getType() const;
};
