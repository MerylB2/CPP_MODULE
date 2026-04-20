/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:53:30 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

// CLASSE SANS VIRTUAL - Demontre ce qui se passe SANS polymorphisme :
//
// PROBLEME sans virtual :
// WrongAnimal* ptr = new WrongCat();
// ptr->makeSound(); -> appelle WrongAnimal::makeSound() PAS WrongCat!
// Le compilateur regarde le TYPE DU POINTEUR, pas le type reel de l'objet
//
// CONSEQUENCE :
// - Meme si ptr pointe vers un WrongCat, c'est WrongAnimal::makeSound() qui est appelee
// - Le destructeur de WrongCat ne sera pas appele -> fuite memoire potentielle
//
// Cette classe existe pour COMPARER avec Animal et comprendre l'importance de virtual

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& wrong);
		WrongAnimal& operator=(const WrongAnimal& wrong);
		~WrongAnimal();           // PAS virtual -> destruction incorrecte

		void makeSound() const;   // PAS virtual -> pas de polymorphisme
		std::string getType() const;
};
