
#include <string>
#include <iostream>

int	main(void)
{
	std::string		string("HI THIS IS BRAIN");
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Address of the string variable: " << stringPTR;
}
