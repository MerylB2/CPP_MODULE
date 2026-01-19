/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/16 09:48:34 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include " Brain.hpp"

// Cat herite de Animal - a son propre Brain (deep copy obligatoire)
class Cat : public Animal
{
	private:
		Brain* brain;  // Allocation dynamique, deep copy obligatoire

	public:
		Cat();
		Cat(const Cat& newCat);
		Cat& operator=(const Cat& other_Cat);
		~Cat();

		void makeSound() const;
		Brain* getBrain() const;
};
