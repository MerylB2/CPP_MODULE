/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:52:45 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 17:25:00 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
	
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	
	void announce(void);
	void setName(std::string name);
};

// Allocates a horde of zombies on the heap and returns its pointer
Zombie* zombieHorde(int N, std::string name);

#endif