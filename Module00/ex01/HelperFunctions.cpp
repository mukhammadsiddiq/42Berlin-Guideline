/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:16:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/05 12:24:29 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// main dashboard
void	printMenu() {
	std::cout << CYAN << BOLD;
	std::cout << "===================================" << std::endl;
	std::cout << "📞  WELCOME TO YOUR PHONEBOOK  📖  " << std::endl;
	std::cout << "===================================" << RESET << std::endl;
	
	std::cout << YELLOW << BOLD << "Please choose an option:" << RESET << std::endl;
	std::cout << GREEN << BOLD << "[1] ADD     " << BLUE << "[2] SEARCH     " << RED << "[3] EXIT" << RESET << std::endl;

	std::cout << CYAN << "-----------------------------------" << RESET << std::endl;
}

// string checker for phone number
bool	ftis_digit(std::string number)
{
	int i = 0;
	if (number[i] == '+')
		i++;
	for (; i < number.length(); i++){
		if (!isdigit(number[i])) return false;
	}
	return (true);
}

// Dashboard for Adding contacts and its functionality
bool	addContact(PhoneBook &book) {
	std::string fname, lname, nname, pnumber, secret;

	std::cout << CYAN << BOLD;
	std::cout << "===================================" << std::endl;
	std::cout << "📋  ADD A NEW CONTACT  📇 " << std::endl;
	std::cout << "===================================" << RESET << std::endl;

	//std::cin.ignore(); // Ignore any leftover newline characters

	std::cout << YELLOW << "👉 First Name: " << RESET;
	std::getline(std::cin, fname);

	std::cout << YELLOW << "👉 Last Name: " << RESET;
	std::getline(std::cin, lname);

	std::cout << YELLOW << "👉 Nickname: " << RESET;
	std::getline(std::cin, nname);

	std::cout << YELLOW << "📞 Phone Number: " << RESET;
	std::getline(std::cin, pnumber);

	std::cout << YELLOW << "🔒 Secret: " << RESET;
	std::getline(std::cin, secret);

	if ((fname.empty() || lname.empty())
		|| (nname.empty() || pnumber.empty() || secret.empty())) {
		std::cout << RED << BOLD << "⚠️  Please fill in all the fields!" << RESET << std::endl;
		return false;
	} 
	if (!ftis_digit(pnumber)){
			std::cout << RED << BOLD << "⚠️  Please provide with correct number!" << RESET << std::endl;
			return false;
	} else {
		Contact contact;
		contact.SetContact(fname, lname, nname, pnumber, secret);
		book.AddBook(contact);
		std::cout << GREEN << BOLD << "✅ Contact added successfully!" << RESET << std::endl;
	}
	return (true);
}

void	SearchContact(PhoneBook &book){
	std::cout << CYAN << BOLD;
	std::cout << "===================================" << std::endl;
	std::cout << "🔍  SEARCH FOR A CONTACT  📇 " << std::endl;
	std::cout << "===================================" << RESET << std::endl;
	std::cout << YELLOW << "👉 Please provide the index number of the contact (0-7): " << RESET;
	std::string index_str;
	std::getline(std::cin, index_str);
	// Convert the index to an integer
	int index = 0;
	index = std::stoi(index_str); // Convert string to integer
	book.DisplayValue(index);
}