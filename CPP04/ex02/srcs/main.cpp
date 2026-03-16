/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/24 16:44:18 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/colors.hpp"

// ex02 : Animal est maintenant une classe ABSTRAITE (makeSound() = 0)
// On ne peut plus faire "new Animal()" -> erreur de compilation
// Seules les classes derivees (Dog, Cat) peuvent etre instanciees
// Decommenter la ligne ci-dessous pour voir l'erreur :

int main()
{
	std::cout << BOLD << YLLW << SOUL << "\n******************** Test Classe Abstraite (ex02) ********************" << RST << std::endl << std::endl;

	// Animal a;              // ERREUR : Animal est abstraite
	// Animal* a = new Animal();  // ERREUR : Animal est abstraite

	std::cout << CYAN << "===== Ces lignes ne compilent PAS (classe abstraite) =====" << RST << std::endl;
	std::cout << GRY2 << "// Animal a;              -> ERREUR" << std::endl;
	std::cout << "// Animal* a = new Animal();  -> ERREUR" << RST << std::endl;
	std::cout << std::endl;

	std::cout << GRNN << "===== Mais on peut toujours utiliser Animal* comme type =====" << RST << std::endl;
	Animal* dog = new Dog();  // OK : Dog est concrete
	Animal* cat = new Cat();  // OK : Cat est concrete

	std::cout << PURP << "\n===== makeSound() via pointeur Animal* =====" << RST << std::endl;
	std::cout << "dog->makeSound(): ";
	dog->makeSound();  // Polymorphisme fonctionne toujours
	std::cout << "cat->makeSound(): ";
	cat->makeSound();

	std::cout << RED1 << "\n===== Destruction =====" << RST << std::endl;
	delete dog;
	delete cat;

	std::cout << BOLD << YLLW << SOUL << "\n******************** Test Deep Copy (comme ex01) ********************" << RST << std::endl << std::endl;

	Dog original;
	original.getBrain()->setIdea(0, "I want to play!");

	std::cout << CYAN << "\n===== Copie du Dog =====" << RST << std::endl;
	Dog copy(original);

	std::cout << PURP << "\n===== Verification Deep Copy =====" << RST << std::endl;
	copy.getBrain()->setIdea(0, "I want to sleep!");
	std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << GRY2 << "(Different = deep copy OK)" << RST << std::endl;

	std::cout << RED1 << "\n===== Destruction automatique =====" << RST << std::endl;
	return 0;
}
