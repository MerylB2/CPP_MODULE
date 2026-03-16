/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 11:09:23 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/colors.hpp"

// Brain : chaque Dog/Cat a son propre cerveau alloue dynamiquement (Brain*)
// Deep copy obligatoire : copier le contenu du Brain, pas juste le pointeur
// Sinon 2 objets partagent le meme Brain -> double free ou corruption memoire
// Test : modifier le Brain d'une copie ne doit PAS affecter l'original

int main()
{
	std::cout << BOLD << YLLW << SOUL << "\n******************** Test tableau d'Animaux (sujet) ********************" << RST << std::endl << std::endl;

	const int size = 4;
	Animal* animals[size];

	// Moitie Dogs, moitie Cats
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	std::cout << RED1 << "\n===== Destruction du tableau =====" << RST << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];  // Destructeur virtuel -> appelle Dog/Cat puis Animal

	std::cout << BOLD << YLLW << SOUL << "\n******************** Test Deep Copy Dog ********************" << RST << std::endl << std::endl;

	Dog original;
	original.getBrain()->setIdea(0, "I want to play!");
	original.getBrain()->setIdea(1, "I love my owner!");

	std::cout << CYAN << "\n===== Copie du Dog =====" << RST << std::endl;
	Dog copy(original);  // Deep copy

	std::cout << GRNN << "\n===== Verification Deep Copy =====" << RST << std::endl;
	std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << PURP << "\n===== Modification de la copie =====" << RST << std::endl;
	copy.getBrain()->setIdea(0, "I want to sleep!");
	std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << GRY2 << "(Si different = deep copy OK, si pareil = shallow copy ERREUR)" << RST << std::endl;

	std::cout << BOLD << YLLW << SOUL << "\n******************** Test Deep Copy Cat ********************" << RST << std::endl << std::endl;

	Cat cat1;
	cat1.getBrain()->setIdea(0, "I want fish!");

	std::cout << CYAN << "\n===== Assignation du Cat =====" << RST << std::endl;
	Cat cat2;
	cat2 = cat1;  // Deep copy via operator=

	std::cout << PURP << "\n===== Modification apres assignation =====" << RST << std::endl;
	cat2.getBrain()->setIdea(0, "I want to scratch!");
	std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << RED1 << "\n===== Destruction automatique (stack) =====" << RST << std::endl;
	return 0;
}
