#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	bool		filled;

	public:
	Contact();
	void		set_contact(const std::string fields[5]);
	bool		isfilled() const;
	void		display() const;
	std::string	get_field(int index) const;
};

#endif
