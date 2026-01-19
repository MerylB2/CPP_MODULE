/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 11:00:00 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

// ex02 : Animal est maintenant une classe ABSTRAITE (makeSound() = 0)
// On ne peut plus faire "new Animal()" -> erreur de compilation
// Seules les classes derivees (Dog, Cat) peuvent etre instanciees
// Decommenter la ligne ci-dessous pour voir l'erreur :
// Animal test;  // ERREUR: cannot declare variable 'test' to be of abstract type 'Animal'

int main()
{
	std::cout << "\033[1;93m\033[4m" << "\n******************** Test Classe Abstraite (ex02) ********************" << "\033[0m" << std::endl << std::endl;

	// Animal a;              // ERREUR : Animal est abstraite
	// Animal* a = new Animal();  // ERREUR : Animal est abstraite

	std::cout << "\033[1;96m" << "===== Ces lignes ne compilent PAS (classe abstraite) =====" << "\033[0m" << std::endl;
	std::cout << "// Animal a;              -> ERREUR" << std::endl;
	std::cout << "// Animal* a = new Animal();  -> ERREUR" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[1;92m" << "===== Mais on peut toujours utiliser Animal* comme type =====" << "\033[0m" << std::endl;
	Animal* dog = new Dog();  // OK : Dog est concrete
	Animal* cat = new Cat();  // OK : Cat est concrete

	std::cout << "\033[1;35m" << "\n===== makeSound() via pointeur Animal* =====" << "\033[0m" << std::endl;
	std::cout << "dog->makeSound(): ";
	dog->makeSound();  // Polymorphisme fonctionne toujours
	std::cout << "cat->makeSound(): ";
	cat->makeSound();

	std::cout << "\033[1;91m" << "\n===== Destruction =====" << "\033[0m" << std::endl;
	delete dog;
	delete cat;

	std::cout << "\033[1;93m\033[4m" << "\n******************** Test Deep Copy (comme ex01) ********************" << "\033[0m" << std::endl << std::endl;

	Dog original;
	original.getBrain()->setIdea(0, "I want to play!");

	std::cout << "\033[1;96m" << "\n===== Copie du Dog =====" << "\033[0m" << std::endl;
	Dog copy(original);

	std::cout << "\033[1;35m" << "\n===== Verification Deep Copy =====" << "\033[0m" << std::endl;
	copy.getBrain()->setIdea(0, "I want to sleep!");
	std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << "(Different = deep copy OK)" << std::endl;

	std::cout << "\033[1;91m" << "\n===== Destruction automatique =====" << "\033[0m" << std::endl;
	return 0;
}
