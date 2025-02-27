/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:11:59 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/05 13:59:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv){
	(void) argv;
	(void) argc;
	PhoneBook	book;

	while (true){
		printMenu();
		std::string	command;
		std::getline(std::cin, command);
		ft_upper(command);
		if (command.compare("ADD") == 0 || command.compare("1") == 0){
			if (!addContact(book)){
				std::cout << RED << BOLD << "⚠️  Unsuccessfull !" << RESET << std::endl;
			}
		}
		if (command.compare("SEARCH") == 0 || command.compare("2") == 0) {
			SearchContact(book);
		}
		if (command.compare("EXIT") == 0 || command.compare("3") == 0){
			return(0);
		}
	}
	return (0);
}