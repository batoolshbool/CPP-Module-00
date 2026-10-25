/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:08:00 by bshbool           #+#    #+#             */
/*   Updated: 2026/10/25 11:24:50 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : filled(false)
{
}

void Contact::set_contact(const std::string fields[5])
{
	first_name = fields[0];
	last_name = fields[1];
	nickname = fields[2];
	phone_number = fields[3];
	darkest_secret = fields[4];
	filled = true;
}

bool Contact::isfilled() const
{
	return filled;
}

std::string Contact::get_field(int index) const
{
	switch (index)
	{
		case 0: return first_name;
		case 1: return last_name;
		case 2: return nickname;
		case 3: return phone_number;
		case 4: return darkest_secret;
	}
	return "";
}

void Contact::display() const
{
	std::cout << "First name: " << first_name << '\n';
	std::cout << "Last name: " << last_name << '\n';
	std::cout << "Nickname: " << nickname << '\n';
	std::cout << "Phone number: " << phone_number << '\n';
	std::cout << "Darkest secret: " << darkest_secret << '\n';
}
