/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:39:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 12:20:39 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{	
	typedef void (Harl::*ft_Harl)(void);
	
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	ft_Harl functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	int i_level = 0;
	while (i_level < 4 && levels[i_level].compare(level))
		i_level++;
	switch (i_level)
	{
		case 0:
			(this->*functions[0])();
		case 1:
			(this->*functions[1])();
		case 2:
			(this->*functions[2])();
		case 3:
			(this->*functions[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;	
	}
}








/* first way i have implemented */
// int Harl::getLevel(std::string level)
// {
// 	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		while (levels[i] == level)
// 			return i;
// 	}
// 	return -1;
// }

// void Harl::complain(std::string level)
// {
// 	typedef void (Harl::*ft_Harl)(void);
	
// 	ft_Harl functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
// 	int i_level = getLevel(level);
// 	while (i_level >= 0 && i_level < 4)
// 	{
// 		(this->*functions[i_level])();
// 		return;
// 	}
// }