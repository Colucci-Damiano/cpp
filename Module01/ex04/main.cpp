
#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int					length1;
		int					length2;
		size_t				index;
		size_t				tmpIndex;
		std::string			fileName = av[1];
		std::string			s1 = av[2];
		std::string			s2 = av[3];
		std:: ifstream		ifs(fileName.c_str());
		std::string			buffer;
		std::string			output;

		length1 = s1.length();
		length2 = s2.length();
		if (!ifs.good())
		{
			std::cout << "Cannot open file " << fileName << std::endl;
			return (1);
		}
		std::ofstream		ofs((fileName + ".replace").c_str());
		if (!ofs.good())
		{
			std::cout << "Cannot open file output file" << fileName + ".replace" << std::endl;
			return (2);
		}
		std::getline(ifs, buffer, (char)EOF);
		ifs.close();
		index = 0;
		do
		{
			tmpIndex = buffer.find(s1, index);
			output.append(buffer.substr(index, tmpIndex - index));
			if (tmpIndex == std::string::npos)
				break ;
			output.append(s2);
			index = tmpIndex + length1;
		}
		while (tmpIndex != std::string::npos);
		ofs << output;
		ofs.close();
	}
	return (0);
}