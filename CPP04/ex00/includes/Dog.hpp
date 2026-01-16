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

// Dog herite de Animal - polymorphisme avec virtual
class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& newDog);
		Dog& operator=(const Dog& other_Dog);
		~Dog();

		void makeSound() const;  // Override de Animal::makeSound()
};
