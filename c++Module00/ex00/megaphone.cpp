#include <iostream>

void	ft_toupper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 32;
		i++;
	}
}

int	main(int ac, char **av)
{	
	if (ac == 2)
	{
		ft_toupper(av[1]);
		std::cout << av[1] << std::endl;
	}
	else
		std::cout << std::endl;
	return (0);
}