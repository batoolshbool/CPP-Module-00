#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iomanip>
# include <cctype>

class PhoneBook
{
	private:
	Contact	contacts[8];
	int		next_index;
	int		count;

	public:
	PhoneBook();
	
	void	add_contact();
	void	search_contact() const;
};

#endif
