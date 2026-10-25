/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 10:40:18 by bshbool           #+#    #+#             */
/*   Updated: 2026/10/25 10:43:28 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

void	print_argument(char *argument)
{
	while (*argument != '\0')
	{
		if (isalpha(*argument))
			std::cout << (char)toupper(*argument);
		else
			std::cout << *argument;
		argument++;
	}
}

int	main(int argc, char **argv)
{
	char	**args;

	args = ++argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*args != NULL)
		{
			print_argument(*args);
			args++;
		}
		std::cout << std::endl;
	}
	return (0);
}
