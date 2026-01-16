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

// Cat herite de Animal - polymorphisme avec virtual
class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& newCat);
		Cat& operator=(const Cat& other_Cat);
		~Cat();

		void makeSound() const;  // Override de Animal::makeSound()
};
