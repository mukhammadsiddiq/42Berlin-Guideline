/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:42:39 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 21:19:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
	public:
		FragTrap(std::string name);
		~FragTrap();

		FragTrap(const FragTrap &other);
		FragTrap&	operator=(const FragTrap &other);

		void	highFivesGuys(void);
};

#endif