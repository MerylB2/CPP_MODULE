/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:31:18 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/21 12:47:16 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"
#include "../includes/colors.hpp"

// INTERFACES (classes abstraites pures) :
// - ICharacter : interface pour les personnages (getName, equip, unequip, use)
// - IMateriaSource : interface pour les sources de Materia (learnMateria, createMateria)
// Les interfaces definissent un "contrat" : toutes les methodes sont virtuelles pures
// Une classe qui herite d'une interface DOIT implementer toutes ses methodes
//
// CLASSE ABSTRAITE vs INTERFACE :
// - AMateria : classe abstraite (a des attributs + methodes implementees + methodes virtuelles pures)
// - ICharacter/IMateriaSource : interfaces pures (que des methodes virtuelles pures, pas d'attributs)
//
// PATTERN FACTORY (MateriaSource) :
// - learnMateria() : stocke un prototype de Materia
// - createMateria() : cree une copie (clone) du prototype stocke
// Permet de creer des objets sans connaitre leur type concret (polymorphisme)
//
// GESTION MEMOIRE :
// - Character possede ses Materias -> les delete dans son destructeur
// - unequip() ne delete PAS la Materia (le sujet l'exige)
// - Attention aux fuites memoire : les Materias unequip doivent etre gerees

int main()
{
	std::cout << BOLD << YLLW << SOUL << "\n******************** Tests Interface & Materia ********************" << RST << std::endl << std::endl;

	std::cout << CYAN << "===== Creation MateriaSource (Factory Pattern) =====" << RST << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << GRNN << "\n===== Creation Character =====" << RST << std::endl;
	ICharacter* me = new Character("me");

	std::cout << BLUE << "\n===== Creation et Equip Materia =====" << RST << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << GRNN << "\n===== Creation Character cible =====" << RST << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << PURP << "\n===== Use Materia (polymorphisme) =====" << RST << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << BOLD << YLLW << SOUL << "\n******************** Tests Supplementaires ********************" << RST << std::endl << std::endl;

	std::cout << ORNG << "===== Test createMateria avec type inconnu =====" << RST << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (unknown == NULL)
		std::cout << GRY2 << "createMateria(\"fire\") retourne NULL (type inconnu)" << RST << std::endl;

	std::cout << ORNG << "\n===== Test use avec index invalide =====" << RST << std::endl;
	me->use(-1, *bob);
	me->use(10, *bob);

	std::cout << ORNG << "\n===== Test equip inventaire plein =====" << RST << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << GRY2 << "Inventaire plein (4 slots), tentative d'equip supplementaire:" << RST << std::endl;
	AMateria* extra = src->createMateria("ice");
	me->equip(extra);
	delete extra;

	std::cout << ORNG << "\n===== Test unequip =====" << RST << std::endl;
	AMateria* unequipped = me->getMateria(0);
	me->unequip(0);
	std::cout << GRY2 << "Materia unequip (pas delete, doit etre geree manuellement)" << RST << std::endl;
	delete unequipped;

	std::cout << ORNG << "\n===== Test copie Character (deep copy) =====" << RST << std::endl;
	Character original("Original");
	original.equip(src->createMateria("ice"));
	Character copie(original);
	std::cout << GRY2 << "Original: " << original.getName() << ", Copie: " << copie.getName() << RST << std::endl;

	std::cout << RED1 << "\n===== Destruction (ordre inverse) =====" << RST << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}