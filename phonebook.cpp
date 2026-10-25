/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:09:41 by bshbool           #+#    #+#             */
/*   Updated: 2026/10/25 11:28:07 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : next_index(0), count(0)
{
}

static bool isblank(const std::string &text)
{
	std::string::size_type i = 0;
	while(i < text.length())
	{
		if (!std::isspace(static_cast<unsigned char>(text[i]))) //if its signed..chars above 127 become negative, undefinedo elbehavioro
			return false;
		++i;
	}
	return true;
}

void PhoneBook::add_contact()
{
	std::string			fields[5];
	const std::string	prompts[5] =
	{
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: "
	};

	int i = 0;
	while(i < 5)
	{
		while (true)
		{
			std::cout << prompts[i];
			if (!std::getline(std::cin, fields[i]))
				return;
			if (!isblank(fields[i]))
				break;
			std::cout << "Field cannot be empty.\n";
		}
		++i;
	}

	contacts[next_index].set_contact(fields);
	next_index = (next_index + 1) % 8;
	if (count < 8)
		++count;

	std::cout << "Contact added.\n";
}

static std::string format_field(const std::string &text)
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	return text;
}

void PhoneBook::search_contact() const
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty.\n";
		return;
	}

	std::cout << std::right
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First name" << "|"
		<< std::setw(10) << "Last name" << "|"
		<< std::setw(10) << "Nickname" << '\n';

	for (int i = 0; i < count; ++i)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << format_field(contacts[i].get_field(0)) << "|"
			<< std::setw(10) << format_field(contacts[i].get_field(1)) << "|"
			<< std::setw(10) << format_field(contacts[i].get_field(2)) << '\n';
	}

	std::string input;
	std::cout << "Enter contact index: ";
	if (!std::getline(std::cin, input))
		return;

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index.\n";
		return;
	}

	int index = input[0] - '0';

	if (index >= count || !contacts[index].isfilled())
	{
		std::cout << "Contact does not exist.\n";
		return;
	}

	contacts[index].display();
}
