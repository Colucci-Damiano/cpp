
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{

private:

	Contact				_contacts[8];
	int					_size;
	unsigned long int	_iterator;
	bool				_running;
	void				_incrementIterator(void);
	std::string			_instertField(std::string output) const;
	std::string			_insertNumber(std::string output) const;
	int					_insertIdSearch(void) const;

public:

	PhoneBook(void);
	~PhoneBook(void);
	void	help(void) const;
	void	add(void);
	void	search(void) const;
	bool	get_Running(void) const;
	void	set_Running(bool value);

};

#endif