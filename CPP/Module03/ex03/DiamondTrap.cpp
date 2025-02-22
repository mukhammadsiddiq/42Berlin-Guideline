/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:54:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 23:03:13 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name){
		_hitPoints = FragTrap::_hitPoints;
		_energyPoints = ScavTrap::_energyPoints;
		_AttackDamage = FragTrap::_AttackDamage;
	}

void	DiamondTrap::whoAmi(void){
	std::cout << "I am DiamondTrap" << _name << std::endl;
}

DiamondTrap::~DiamondTrap() {}


