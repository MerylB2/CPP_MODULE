/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:58:17 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 11:01:19 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

// BRAIN - Classe pour illustrer la DEEP COPY :
// Chaque Dog/Cat possede un Brain* alloue avec new
//
// PROBLEME de la SHALLOW COPY (copie superficielle) :
// Dog d1; Dog d2 = d1;  // Si shallow copy : d1.brain et d2.brain pointent vers le meme Brain!
// Modifier d2.brain modifie aussi d1.brain -> comportement incorrect
// delete d1 puis delete d2 -> double free -> crash!
//
// SOLUTION - DEEP COPY (copie profonde) :
// Dans Dog(const Dog& src) : this->brain = new Brain(*src.brain);
// Chaque Dog a son propre Brain independant
//
// REGLE : Si une classe a des pointeurs -> implementer deep copy dans :
// 1. Constructeur de copie
// 2. Operateur d'assignation (operator=)
// 3. Destructeur (delete les pointeurs)

class Brain
{
	private:
		std::string ideas[100];  // 100 idees par Brain

	public:
		Brain();
		Brain(const Brain& newBrain);              // Deep copy des 100 idees
		Brain& operator=(const Brain& other_Brain); // Deep copy des 100 idees
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};