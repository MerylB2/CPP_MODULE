/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/24 14:46:24 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/colors.hpp"

// Polymorphisme : "virtual" permet d'appeler la bonne methode selon le type REEL
// Animal* a = new Dog(); a->makeSound(); -> avec virtual = "Woof!", sans = "Animal sound"
// new/delete : allocation dynamique necessaire pour le polymorphisme avec pointeurs
// Destructeur virtuel : obligatoire sinon le destructeur derive n'est pas appele
// WrongAnimal : demontre le comportement SANS virtual (toujours la methode de base)
//
// Note Stack : "Animal a = Dog();" provoque le SLICING (l'objet Dog est coupe en Animal)
// La partie Dog est perdue, seule la partie Animal reste -> polymorphisme impossible
// Solution : utiliser pointeurs (Animal*) ou references (Animal&) pour garder le type reel

// Cpdt on utilise new pour montrer aussi l'importance du destructeur virtuel
// -> sinon delete ne libere pas correctement la memoire des classes derivees

int main()
{
	std::cout << BOLD << YLLW << SOUL << "\n******************** Test avec VIRTUAL (polymorphisme) ********************" << RST << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << CYAN << "\n===== getType() Test =====" << RST << std::endl;
	std::cout << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;

<<<<<<< HEAD
	std::cout << "\033[1;92m" << "\n===== makeSound() Test (polymorphisme) =====" << "\033[0m" << std::endl;
	std::cout << "i(cat)->makeSound(): ";
=======
	std::cout << GRNN << "\n===== makeSound() Test (polymorphisme) =====" << RST << std::endl;
	std::cout << "i->makeSound(): ";
>>>>>>> d2a652aa1f2ba66b70276647c788c33ccf3901aa
	i->makeSound();
	std::cout << "j(dog)->makeSound(): ";
	j->makeSound();
	std::cout << "meta->makeSound(): ";
	meta->makeSound();

	std::cout << RED1 << "\n===== Destruction (ordre inverse) =====" << RST << std::endl;
	delete i;
	delete j;
	delete meta;

	std::cout << BOLD << YLLW << SOUL << "\n************** Test SANS virtual (pas de polymorphisme) **************" << RST << std::endl << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << CYAN << "\n===== getType() Test =====" << RST << std::endl;
	std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;

	std::cout << PURP << "\n===== makeSound() Test (PAS de polymorphisme) =====" << RST << std::endl;
	std::cout << "wrongCat->makeSound(): ";
	wrongCat->makeSound();
	std::cout << "wrongMeta->makeSound(): ";
	wrongMeta->makeSound();

	std::cout << RED1 << "\n===== Destruction =====" << RST << std::endl;
	delete wrongCat;
	delete wrongMeta;

	return 0;
}
