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

// Classe de base pour le polymorphisme
class Animal
{
	protected:
		std::string type;  // Protected : accessible par les classes derivees

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& newAnimal);
		Animal& operator=(const Animal& other_Animal);
		virtual ~Animal();  // Destructeur virtuel obligatoire pour le polymorphisme

		virtual void makeSound() const;  // Virtuel : comportement different selon la classe
		std::string getType() const;    
};
