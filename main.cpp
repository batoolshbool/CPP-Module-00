/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:25:49 by bshbool           #+#    #+#             */
/*   Updated: 2026/10/25 11:28:37 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";

		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			phoneBook.add_contact();
		else if (command == "SEARCH")
			phoneBook.search_contact();
		else if (command == "EXIT")
			break;
	}

	return 0;
}