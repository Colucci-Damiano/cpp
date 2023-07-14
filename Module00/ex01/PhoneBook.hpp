//FIELDS
//	array of contacts (maximum 8)

/*
FUNCTIONS
	ADD: add a new contact; if maximum is reached the oldest is deleted
	SEARCH: 1) Display all saved contacts		| id | first name | last name | nickname |

				(10 char for column; if max is reached a dot substitute the last displayable char)
			2)	Prompt the user for the index; manage error on index
				In case of match display every user field per line
	EXIT: the program quits
*/

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