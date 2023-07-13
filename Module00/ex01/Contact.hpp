
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{

private:
	std::string const	_firstName;
	std::string const	_lastName;
	std::string const	_nickName;
	std::string const	_phoneNumber;
	std::string const	_darkestSecret;

public:
	Contact(void);
	Contact(std::string const fN, std::string const lN, std::string const nN, \
	std::string const pN, std::string const dS);
	~Contact(void);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
};

#endif
