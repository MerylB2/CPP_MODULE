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

// Brain : chaque Dog/Cat a son propre cerveau (deep copy obligatoire)
class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& newBrain);
		Brain& operator=(const Brain& other_Brain);
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};