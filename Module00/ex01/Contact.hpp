
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{

private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_phoneNumber;
	std::string		_darkestSecret;

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

	void		setFirstName(std::string name);
	void		setLastName(std::string lastName);
	void		setNickName(std::string nick);
	void		setPhoneNumber(std::string phone);
	void		setDarkestSecret(std::string secret);

	void		displaySearchContact(int id) const;
	void		displayFullContact(void) const;
	std::string	resizeField(std::string field) const;
};

#endif
