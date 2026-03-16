/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:54:51 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

// DEMONSTRATION du comportement SANS virtual :
// WrongCat redefini makeSound() MAIS ca ne fonctionne pas via WrongAnimal*
//
// Comparaison :
// | Avec virtual (Animal/Cat)      | Sans virtual (WrongAnimal/WrongCat) |
// |--------------------------------|-------------------------------------|
// | Animal* a = new Cat();         | WrongAnimal* w = new WrongCat();    |
// | a->makeSound(); -> "Meow!"     | w->makeSound(); -> "WrongAnimal!"   |
// | Appelle Cat::makeSound()       | Appelle WrongAnimal::makeSound()    |

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& wrong_Cat);
		WrongCat& operator=(const WrongCat& wrong_Cat);
		~WrongCat();

		void makeSound() const;  // JAMAIS appelee via WrongAnimal* (pas de virtual)
};
