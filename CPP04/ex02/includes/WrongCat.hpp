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

// WrongCat herite de WrongAnimal - SANS polymorphisme (pas de virtual)
class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& wrong_Cat);
		WrongCat& operator=(const WrongCat& wrong_Cat);
		~WrongCat();

		void makeSound() const;  // Ne sera PAS appelee via un pointeur WrongAnimal*
};
