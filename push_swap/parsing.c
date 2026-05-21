#include "push_swap.h"

ft_lst_new(char *str)
{
	
}



int	ft_flag(char *av,)
{
	int		i;
	char	bench[] = "--bench";
	char	complex[] = "--complex";
	char	simple[] = "--simple";
	char	medium[] = "--medium";
	char	adaptive[] = "--adaptive";

	if (ft_strcmp(av, bench) == 0)
	{
		fontcion_bench();
		return (1);
	}
	else if (ft_strcmp(av, complex) == 0)
	{
		fontcion_complex();
		return (1);
	}
	else if (ft_strcmp(av, simple) == 0)
	{
		fontcion_simple();
		return (1);
	}
	else if (ft_strcmp(av, medium) == 0)
	{
		fontcion_medium() return (1);
	}
	else if (ft_strcmp(av, adaptive) == 0)
	{
		fontcion_adaptive();
		return (1);
	}
	ft_putstr("error");
	return (0);
}



int	main(int ac, char **av)
{
	int i;
	int j;


	j = 1;
	i = 0;
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] == '-' && av[j][i + 1] == '-')
				ft_flag(av[j]);

            else if(ft_verify_digit(av[j]))
				ft_lst_new(av[j]);
				ft_lst_add_back(av[j]);                
			i++;
		}
        j++;
	}

	write(1, "\n", 1);
	return (0);
}