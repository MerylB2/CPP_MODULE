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

// Brain : chaque Dog/Cat a son propre cerveau alloue dynamiquement (Brain*)
// Deep copy obligatoire : copier le contenu du Brain, pas juste le pointeur
// Sinon 2 objets partagent le meme Brain -> double free ou corruption memoire
// Test : modifier le Brain d'une copie ne doit PAS affecter l'original

int main()
{
	std::cout << "\033[1;93m\033[4m" << "\n******************** Test tableau d'Animaux (sujet) ********************" << "\033[0m" << std::endl << std::endl;

	const int size = 4;
	Animal* animals[size];

	// Moitie Dogs, moitie Cats
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	std::cout << "\033[1;91m" << "\n===== Destruction du tableau =====" << "\033[0m" << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];  // Destructeur virtuel -> appelle Dog/Cat puis Animal

	std::cout << "\033[1;93m\033[4m" << "\n******************** Test Deep Copy Dog ********************" << "\033[0m" << std::endl << std::endl;

	Dog original;
	original.getBrain()->setIdea(0, "I want to play!");
	original.getBrain()->setIdea(1, "I love my owner!");

	std::cout << "\033[1;96m" << "\n===== Copie du Dog =====" << "\033[0m" << std::endl;
	Dog copy(original);  // Deep copy

	std::cout << "\033[1;92m" << "\n===== Verification Deep Copy =====" << "\033[0m" << std::endl;
	std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << "\033[1;35m" << "\n===== Modification de la copie =====" << "\033[0m" << std::endl;
	copy.getBrain()->setIdea(0, "I want to sleep!");
	std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << "(Si different = deep copy OK, si pareil = shallow copy ERREUR)" << std::endl;

	std::cout << "\033[1;93m\033[4m" << "\n******************** Test Deep Copy Cat ********************" << "\033[0m" << std::endl << std::endl;

	Cat cat1;
	cat1.getBrain()->setIdea(0, "I want fish!");

	std::cout << "\033[1;96m" << "\n===== Assignation du Cat =====" << "\033[0m" << std::endl;
	Cat cat2;
	cat2 = cat1;  // Deep copy via operator=

	std::cout << "\033[1;35m" << "\n===== Modification apres assignation =====" << "\033[0m" << std::endl;
	cat2.getBrain()->setIdea(0, "I want to scratch!");
	std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\033[1;91m" << "\n===== Destruction automatique (stack) =====" << "\033[0m" << std::endl;
	return 0;
}
